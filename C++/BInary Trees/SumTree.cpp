#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val): data(val), left(nullptr), right(nullptr){}
};

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

pair<bool, int> isSumTree(Node* root){
    if(root == nullptr) return {true, 0};
    if(root->left == nullptr && root->right == nullptr) return {true, root->data};

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root->data == leftAns.second + rightAns.second;

    if(left && right && condn) return {true, 2*(root->data)};
    else return {false, 0};
   
}

int main(){

    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    bool ans = isSumTree(root).first;
    if(ans) cout << "Sum Tree: True"<< endl;
    else cout << "Sum Tree: False"<< endl;

    delete(root);
 
    return 0;
}