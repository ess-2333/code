import argparse #解析命令行参数（--batch-size 128）
#张量计算、网络层定义、激活 / 损失等函数
import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim #更新模型参数
from torchvision import datasets, transforms #加载 MNIST 数据集、做数据预处理（归一化、转张量）
from torch.optim.lr_scheduler import StepLR #学习率调度器，按轮数衰减学习率，避免后期训练震荡

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        # 卷积层1：输入通道1（灰度图），输出通道32，卷积核3x3，步长1
        self.conv1 = nn.Conv2d(1, 32, 3, 1)
        # 卷积层2：输入通道32，输出通道64，卷积核3x3，步长1
        self.conv2 = nn.Conv2d(32, 64, 3, 1)
        # Dropout层：随机丢弃25%的神经元，防止过拟合 ？
        self.dropout1 = nn.Dropout(0.25)
        self.dropout2 = nn.Dropout(0.5)
        # 全连接层1：输入9216维（由卷积层输出尺寸计算而来），输出128维
        self.fc1 = nn.Linear(9216, 128)
        # 全连接层2：输出10维（对应0-9共10个数字）
        self.fc2 = nn.Linear(128, 10)

    def forward(self, x):
        # 前向传播：卷积→激活→卷积→激活→池化→Dropout→展平→全连接→Dropout→输出
        x = self.conv1(x)
        x = F.relu(x) # ReLU激活，保留非线性
        x = self.conv2(x)
        x = F.relu(x)
        x = F.max_pool2d(x, 2)
        x = self.dropout1(x)
        x = torch.flatten(x, 1)
        x = self.fc1(x)
        x = F.relu(x)
        x = self.dropout2(x)
        x = self.fc2(x)
        output = F.log_softmax(x, dim=1) # 对数softmax，适配NLLLoss损失函数
        return output


def train(args, model, device, train_loader, optimizer, epoch):
    model.train() # 切换到训练模式（Dropout/BatchNorm生效）
    for batch_idx, (data, target) in enumerate(train_loader):
        data, target = data.to(device), target.to(device)
        #初始化
        optimizer.zero_grad()
        # 前向传播，得到预测结果
        output = model(data)
        # 计算损失
        loss = F.nll_loss(output, target)
        # 反向传播，计算梯度
        loss.backward()
        # 更新模型参数
        optimizer.step()

        # 打印训练日志
        if batch_idx % args.log_interval == 0:
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                100. * batch_idx / len(train_loader), loss.item()))
            if args.dry_run:
                break


def test(model, device, test_loader):
    model.eval() # 切换到评估模式（Dropout/BatchNorm失效，用训练好的参数）
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for data, target in test_loader:
            data, target = data.to(device), target.to(device)
            output = model(data)
            # 累加批次损失（reduction='sum'表示求和，最后再平均）
            test_loss += F.nll_loss(output, target, reduction='sum').item()
            # 取预测概率最大的类别作为预测结果
            pred = output.argmax(dim=1, keepdim=True)
            # 统计正确预测的数量
            correct += pred.eq(target.view_as(pred)).sum().item()

    # 计算平均损失和准确率
    test_loss /= len(test_loader.dataset)

    print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(test_loader.dataset),
        100. * correct / len(test_loader.dataset)))


def main():
    # Training settings
    parser = argparse.ArgumentParser(description='PyTorch MNIST Example')
    parser.add_argument('--batch-size', type=int, default=64, metavar='N',
                        help='input batch size for training (default: 64)')
    parser.add_argument('--test-batch-size', type=int, default=1000, metavar='N',
                        help='input batch size for testing (default: 1000)')
    parser.add_argument('--epochs', type=int, default=5, metavar='N',
                        help='number of epochs to train (default: 14)')
    parser.add_argument('--lr', type=float, default=1.0, metavar='LR',
                        help='learning rate (default: 1.0)')
    parser.add_argument('--gamma', type=float, default=0.7, metavar='M',
                        help='Learning rate step gamma (default: 0.7)')
    parser.add_argument('--no-accel', action='store_true',
                        help='disables accelerator')
    parser.add_argument('--dry-run', action='store_true',
                        help='quickly check a single pass')
    parser.add_argument('--seed', type=int, default=1, metavar='S',
                        help='random seed (default: 1)')
    parser.add_argument('--log-interval', type=int, default=10, metavar='N',
                        help='how many batches to wait before logging training status')
    parser.add_argument('--save-model', action='store_true', 
                        help='For Saving the current Model')
    args = parser.parse_args()

    use_accel = not args.no_accel and torch.cuda.is_available()

    torch.manual_seed(args.seed) # 设置随机种子

    if use_accel:
        device = torch.device("cuda")  #用cuda而不是accelerator，处理 GPU 的核心是cuda相关 API。
    else:
        device = torch.device("cpu")

    # 数据加载的参数
    train_kwargs = {'batch_size': args.batch_size}
    test_kwargs = {'batch_size': args.test_batch_size}
    if use_accel:
        accel_kwargs = {'num_workers': 1,
                        'persistent_workers': True,
                       'pin_memory': True,
                       'shuffle': True}
        train_kwargs.update(accel_kwargs)
        test_kwargs.update(accel_kwargs)

    # 数据预处理：转张量 + 归一化
    transform=transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.1307,), (0.3081,))
        ])

    # 加载MNIST数据集
    dataset1 = datasets.MNIST('../data', train=True, download=True,
                       transform=transform)
    dataset2 = datasets.MNIST('../data', train=False,
                       transform=transform)

    # 构建数据加载器（迭代器，按批次返回数据）
    train_loader = torch.utils.data.DataLoader(dataset1,**train_kwargs)
    test_loader = torch.utils.data.DataLoader(dataset2, **test_kwargs)

    model = Net().to(device) # 初始化模型并放到指定设备
    optimizer = optim.Adadelta(model.parameters(), lr=args.lr) #优化器
    scheduler = StepLR(optimizer, step_size=1, gamma=args.gamma) # 学习率调度器：每轮衰减为原来的0.7倍

    #训练循环
    for epoch in range(1, args.epochs + 1):
        train(args, model, device, train_loader, optimizer, epoch)
        test(model, device, test_loader)
        scheduler.step() # 更新学习率

    # 保存模型（只保存参数，不保存整个模型，节省空间）
    if args.save_model:
        torch.save(model.state_dict(), "mnist_cnn.pt")



if __name__ == '__main__':
    main()
