def isSafe(newx, newy, arr, visited, n):
    if (newx >= 0 and newx < n) and (newy >= 0 and newy < n) and (visited[newx][newy] == 0) and (arr[newx][newy] == 1):
        return True
    else:
        return False 

def solve(x, y, arr, ans, visited, path, n):
    if (x == n - 1) and (y == n - 1):
        ans.append(path)
        return
    
    visited[x][y] = 1

    # DOWN 
    if(isSafe(x + 1, y, arr, visited, n)):
        solve(x + 1, y, arr, ans, visited, path + 'D', n)
    
    # LEFT
    if(isSafe(x, y - 1, arr, visited, n)):
        solve(x, y - 1, arr, ans, visited, path + 'L', n)
    
    # RIGHT
    if(isSafe(x, y + 1, arr, visited, n)):
        solve(x, y + 1, arr, ans, visited, path + 'R', n)
    
    # UP
    if(isSafe(x - 1, y, arr, visited, n)):
        solve(x - 1, y, arr, ans, visited, path + 'U', n)
    
    visited[x][y] = 0

def searchMaze(arr, n):
    if arr[0][0] == 0:
        return
    ans = []
    visited = [[0 for _ in range(n)] for _ in range(n)]
    path = ""
    solve(0, 0, arr, ans, visited, path, n)
    return ans



if __name__ == "__main__":
    arr = [
        [1, 0, 0, 0],
        [1, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 1, 1, 1],
    ]

    n = len(arr)

    result = searchMaze(arr, n)
    print(result)
