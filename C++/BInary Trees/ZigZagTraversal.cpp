#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(nullptr), right(nullptr){}
};

vector<int> ZigZagTraversal(Node* root){
    vector<int> result;
    if(root == nullptr) return result;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if(frontNode->left) q.push(frontNode -> left);
            if(frontNode->right) q.push(frontNode -> right);

        }

        leftToRight = !leftToRight;

        for(auto i: ans){
            result.push_back(i);
        }
    }
    return result;
}


int main(){

    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    vector<int> arr = ZigZagTraversal(root);

    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
    
    delete (root);

    return 0;
}