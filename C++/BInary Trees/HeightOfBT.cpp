#include <iostream>
#include <bits/stdc++.h>
// #include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int Height(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<pair<Node *, int>> q;
    int height = 0;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *node = q.front().first;
        int level = q.front().second;
        q.pop();

        height = max(height, level);

        if (node->left)
        {
            q.push({node->left, level + 1});
        }

        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    return height + 1;
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root; // Delete the current node AFTER deleting children
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->left->left = new Node(9);

    int ans = Height(root);
    cout << "Height of BT is: " << ans << endl;

    // ---------------------------

    deleteTree(root);

    return 0;
}