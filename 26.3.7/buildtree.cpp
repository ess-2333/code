#include <iostream>
#include <string>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(char val) : data(val), leftchild(nullptr), rightchild(nullptr) {}
}; 

int pos = 0;

TreeNode *build(string str){
    int n = str.size();
    if(pos >= n){
        return nullptr;
    }
    char c = str[pos];
    pos++;
    if(c == '#') return nullptr;
    TreeNode *root = new TreeNode(c);
    root->leftchild = build(str);
    root->rightchild = build(str);
    return root;
}

void inorder(TreeNode *root){
    if(root == nullptr) return;
    inorder(root->leftchild);
    cout << root->data << " ";
    inorder(root->rightchild);
}

//释放内存
void deleteTree(TreeNode *root){
    if(root == nullptr) return;
    deleteTree(root->leftchild);
    deleteTree(root->rightchild);
    delete root;
}

int main(){
    string str ;
    while(cin >> str){
        TreeNode *root = build(str);
        inorder(root);
        deleteTree(root);
    }
}