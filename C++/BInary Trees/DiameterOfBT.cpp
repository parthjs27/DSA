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
    int left = Height(root->left);
    int right = Height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int Diameter(Node* root){
    if(root == nullptr)
        return 0;
    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);
    int totalDiameter = Height(root->left) + Height(root->right) + 1;

    return max({leftDiameter, rightDiameter, totalDiameter});

}

pair<int, int>DiameterOptimized(Node* root){

    if(root == nullptr)
        return {0, 0};
        
    pair<int, int> left = DiameterOptimized(root->left);
    pair<int, int> right = DiameterOptimized(root->right);

    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int totalDiameter = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max({leftDiameter, rightDiameter, totalDiameter});
    ans.second = max(left.second, right.second) + 1;

    return ans;
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

    // int diameter = Diameter(root);
    int diameter = DiameterOptimized(root).first;
    cout << "Diameter of BT is: " << diameter << endl;

    // ---------------------------

    deleteTree(root);

    return 0;
}