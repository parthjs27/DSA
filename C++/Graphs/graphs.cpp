#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class graph{
    public:
        unordered_map<T, list<T>> adj;

        void addEdge(T u, T v, bool direction){
            // Direction = 0 -> Undirected
            // Direction = 1 -> Directed
            adj[u].push_back(v);
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i: adj){
                cout << i.first << " -> ";
                cout << "[ ";
                for (auto j: i.second){
                    cout << j << ", ";   
                }
                cout << " ]"; 
                cout << endl;            
            }
        }
};

int main(){

    int n;
    cout << "Enter the no. of vertices(nodes): "<< endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: "<< endl;
    cin >> m;

    graph<int> g;  //  For char grpah change to 'char'

    int u, v;     //  For char grpah change to 'char'
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        // Udirected Graph
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}

// 0 1  
// 0 4
// 1 2
// 1 3
// 2 3
// 3 4

