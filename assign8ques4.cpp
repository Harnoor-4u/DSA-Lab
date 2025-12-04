#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int d) {
    if (root == NULL)
        return new Node(d);
    if (d < root->data)
        root->left = insert(root->left, d);
    else if (d > root->data)
        root->right = insert(root->right, d);
    return root;
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, d;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> d;
        root = insert(root, d);
    }

    cout << "\nInorder traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "\nThe given binary tree IS a BST." << endl;
    else
        cout << "\nThe given binary tree is NOT a BST." << endl;

    return 0;
}

