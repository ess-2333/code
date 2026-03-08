#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(char val) : data(val), leftchild(nullptr), rightchild(nullptr) {}
}; 

TreeNode *creatpost(string preorder, string inorder){
    if(preorder.size() == 0) return nullptr;
    char c = preorder[0];
    TreeNode *root = new TreeNode(c);
    int pos = inorder.find(c); //返回c字符下标
    root->leftchild = creatpost(preorder.substr(1,pos), inorder.substr(0,pos));
    root->rightchild = creatpost(preorder.substr(pos+1), inorder.substr(pos+1));
    return root;
}

void postorder(TreeNode *root){
    if(root == nullptr) return;
    postorder(root->leftchild);
    postorder(root->rightchild);
    cout << root->data << " ";
}

int main(){
    string pre, in;
    while(cin >> pre >> in){
        TreeNode* root = creatpost(pre, in);
        postorder(root);
    }
}