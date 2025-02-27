
class Graph:
    def __init__(self):
        self.adj = {}

    def addEdge(self, u, v, direction):
        if u not in self.adj:
            self.adj[u] = []
        self.adj[u].append(v)

        if direction == 0:
            if v not in self.adj:
                self.adj[v] = []
            self.adj[v].append(u)
    
    def printAdjList(self):
        for node, adjList in self.adj.items():
            print(f'{node} -> {adjList}')


if __name__ == "__main__":
    g = Graph()

    n = int(input('Enter the number of nodes: '))
    m = int(input('Enter the number of edges: '))

    print('Enter edges: ')
    for _ in range(m):
        u, v = map(int, input().split())
        g.addEdge(u, v, 0)
    g.printAdjList()
