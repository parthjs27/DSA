
#include <iostream>
#include<bits/stdc++.h>
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

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root; // Delete the current node AFTER deleting children
}

int Height(Node *root)
{
    if (root == nullptr)
        return 0;
    int left = Height(root->left);
    int right = Height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

bool isBalancedTree(Node* root){
    if (root == nullptr) return true;

    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);

    bool value = abs(Height(root->left) - Height(root->right)) <= 1;

    if(left && right && value) return true;
    else return false;   
}

pair<bool,int> isBalancedOptimized(Node* root){
    if (root == nullptr) return {true, 0};
    pair<bool, int> left = isBalancedOptimized(root->left);
    pair<bool, int> right = isBalancedOptimized(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool value = abs(left.second - right.second) <= 1;
    int height = max(left.second, right.second) + 1;

    if(leftAns && rightAns && value) return {true, height};
    else return{false, height};
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->right = new Node(6);
    // root->left->right->left = new Node(7);
    // root->right->right->left = new Node(8);
    // root->right->right->left->left = new Node(9);

    // bool balanced = isBalancedTree(root);
    bool isBalanced = isBalancedOptimized(root).first;

    if(isBalanced) cout<<"Tree is Balanced";
    else cout << "Tree is not balanced";

    deleteTree(root);

    return 0;
}