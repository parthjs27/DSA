
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Node(int val)
    // {
    //     data = val;
    //     left = nullptr;
    //     right = nullptr;
    // }
    Node(int val): data(val), left(nullptr), right(nullptr){}
};

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root; // Delete the current node AFTER deleting children
}

bool areIdentical(Node* r1, Node* r2){
    if(r1 == nullptr && r2 == nullptr) return true;
    if(r1 != nullptr && r2 == nullptr) return false;
    if(r2 != nullptr && r1 == nullptr) return false;

    bool left = areIdentical(r1->left, r2->left);
    bool right = areIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    if(left && right && value) return true;
    else return false;
}

int main(){

    Node *r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    Node *r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);


    if(areIdentical(r1, r2)) cout << "Tree is Balanced";
    else cout << "Tree is not balanced";

    deleteTree(r1);
    deleteTree(r2);

    return 0;
}