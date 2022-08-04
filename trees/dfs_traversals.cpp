#include <iostream>
using namespace std;

struct tree {
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree *newnode(int val) {
    struct tree *temp = (struct tree*)(malloc(sizeof(struct tree)));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct tree *root){
    if(root->left) inorder(root->left);
    cout<<root->data<<" ";
    if(root->right) inorder(root->right);
}

void preorder(struct tree *root){
    cout<<root->data<<" ";
    if(root->left) inorder(root->left);
    if(root->right) inorder(root->right);
}

void postorder(struct tree *root){
    if(root->left) inorder(root->left);
    if(root->right) inorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct tree *root;
    root = newnode(5);
    root->left = newnode(8);
    root->right = newnode(16);
    root->left->left = newnode(2);
    root->left->left->left = newnode(9);
    root->left->left->right= newnode(11);
    root->right->left = newnode(16);
    root->right->left->right = newnode(32);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root); 
    
}