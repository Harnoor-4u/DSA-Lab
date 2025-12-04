#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root=nullptr;
    }


};

    Node* insert(Node* root,int val){
        Node* newNode = new Node(val);
        if(root==NULL) {
            root=newNode;
            return root;
        }
        if(val > root->data){
            root->right=insert(root->right,val);
        }
        if(val < root->data){
            root->left=insert(root->left,val);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        return;
    }

    void preorder(Node* root){
        if(root==nullptr) return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
        return;
    }

    void postorder(Node* root){
        if(root== nullptr) return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
        return;
    }
int main(){

    BST tree;
    tree.root=insert(tree.root,50);
    insert(tree.root,30);
    insert(tree.root, 70);
    insert(tree.root, 20);
    insert(tree.root, 40);
    insert(tree.root, 60);
    insert(tree.root, 80);

    cout << "Inorder traversal of the BST: ";
    inorder(tree.root);

    cout<<"\npreorder traversal of the bst: ";
    preorder(tree.root);
    cout<<"\npostorder traversal of the bst: ";
    postorder(tree.root);
    
    return 0;
}