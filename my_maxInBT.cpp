#include <iostream>
#include <queue>
#include <climits>
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

queue<int> q; // make q a global variable

void inorder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        q.push(root->key);
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(80);
    root->right = new Node(70);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    inorder(root);
    int maxx = INT_MIN;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        maxx = max(maxx, temp);
    }
    cout << maxx;
    return 0;
}
