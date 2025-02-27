#include <iostream>
#include<bits/stdc++.h>
#include<list>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool checkBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        // ALl neighbours of front node
        for(auto neighbour: adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool detectCycle(vector<vector<int>> &edges, int n, int m){
    // Prepare Adj List
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // For all components of graph
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = checkBFS(i, visited, adj);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

int main(){

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3},
        {4, 5}, {5, 6}, {5, 7}, {6, 8}, {7, 8}, {8, 9}
    };

    int n, m;

    // n represents No. of nodes
    // n represents No. of edges

    m = edges.size();

    unordered_set<int> nodes;
    for(const auto&edge: edges){
        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
    }

    n = nodes.size();

    bool result = detectCycle(edges, n, m);

    if(result){
        cout << "Cycle Detected" << endl;
    }else{
        cout << "No Cycle Detected" << endl;
    }

    // Component 1: 
    // 0 -> 1 -> 2 -> 3

    // Component 2:
    // 4 -> 5 -> 6
    //     |     |
    //     7 ->  8 -> 9

    return 0;
}