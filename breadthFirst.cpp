#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

int height(Node *root) {
    if(root == NULL) 
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}

void printDistK(Node *root, int k){
    if(root == NULL)
        return;
    if(k == 0)
        cout << (root->key) << " ";
    else {
        printDistK(root->left, k-1);
        printDistK(root->right, k-1);
    }
}

void breadthFirst(Node *root) {
    int h = height(root);
    for(int i = 0; i <= h; i++) {
        printDistK(root,i);
    }
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(7);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(15);
    root->right = new Node(30);
    root->right->right = new Node(6);
    
    breadthFirst(root);
    return 0;
}