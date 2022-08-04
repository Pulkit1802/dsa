#include <iostream>
using namespace std;

struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *newNode(int val) {
    struct tree_node *temp = (struct tree_node*)malloc(sizeof(tree_node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct tree_node *insert(struct tree_node *root, int val) {
    if(!root) root = newNode(val);
    else if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct tree_node *root){
    if(root->left) inorder(root->left);
    cout<<root->data<<" ";
    if(root->right) inorder(root->right);
}

int main() {
    int n,val;
    cin>>n;

    struct tree_node *root=NULL;

    for(int i=0;i<n;i++) {
        cin>>val;
        root = insert(root, val);
    }

    inorder(root);

    return 0;
}