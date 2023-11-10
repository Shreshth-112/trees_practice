#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

void printK_dist(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << (root->key) << " ";
    else
    {
        printK_dist(root->left, k - 1);
        printK_dist(root->right, k - 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right = new Node(50);
    root->right->right = new Node(60);
    root->right->right->right = new Node(70);
    root->right->right->right->right = new Node(80);

    inorder(root);
    cout << endl;
    int k = 2;
    printK_dist(root, k);

    return 0;
}