#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <list>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // Store FrontNode
        ans.push_back(frontNode);

        // Traverse all neighbours of FrontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;

    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

    vector<pair<int, int>> arr = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {5, 6}
    };

    int maxVertex = 0;
    for(auto edge: arr){
        maxVertex = max(maxVertex, max(edge.first, edge.second));
    }
    int numVertices = maxVertex + 1;

    vector<int> result = BFS(numVertices, arr);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}