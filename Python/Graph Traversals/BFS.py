
from collections import deque, defaultdict

def prepareAdjList(edges):
    adjList = defaultdict(list)
    for u, v in edges:
        adjList[u].append(v)
        adjList[v].append(u)
    return adjList

def bfs(adjList,visited, ans, node):
    queue = deque([node])
    visited[node] = True
    while queue:
        frontNode = queue.popleft()
        ans.append(frontNode)

        for i in adjList[frontNode]:
            if not visited[i]:
                visited[i] = True
                queue.append(i)

def BFS(vertex, edges):
    ans = []
    adjList = prepareAdjList(edges)
    visited = {i: False for i in range(vertex)}
    for i in range(vertex):
        if not visited[i]:
            bfs(adjList, visited, ans, i)
    return ans

if __name__ == "__main__":
    arr = [(0, 1), (0, 4), (1, 2), (1, 3), (2, 3), (3, 4), (5, 6)]
    maxVertex = 0
    for i in arr:
        maxVertex = max(maxVertex, max(i[0], i[1]))
    numVertices = maxVertex + 1

    result = BFS(numVertices, arr)

    print(result)