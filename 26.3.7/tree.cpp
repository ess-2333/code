#include <iostream>
using namespace std;

struct TreeNode{
    char data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(char val) : data(val), leftchild(nullptr), rightchild(nullptr) {}
}; 

void visit(TreeNode *node){
    cout << node->data << endl;
}

//前序
void preorder(TreeNode *root){
    if(root == nullptr) return;
    visit(root);
    preorder(root->leftchild);
    preorder(root->rightchild);
}

//中序
void inorder(TreeNode *root){
    if(root == nullptr) return;
    inorder(root->leftchild);
    visit(root);
    inorder(root->rightchild);
}

//后序
void postorder(TreeNode *root){
    if(root == nullptr) return;
    postorder(root->leftchild);
    postorder(root->rightchild);
    visit(root);
}