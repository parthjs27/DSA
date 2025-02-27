
def addSoln(ans, board, n):
    temp = []
    for i in range(n):
        for j in range(n):
            temp.append(board[i][j])
    ans.append(temp)

def isSafe(row, col, board, n):
    # ROW
    x = row
    y = col
    while y >= 0:
        if board[x][y] == 'Q':
            return False
        y -= 1

    # UPPER DIAGONAL
    x = row
    y = col
    while x >= 0 and y >= 0:
        if board[x][y] == 'Q':
            return False
        x -= 1
        y -= 1

    # LOWER DIAGONAL
    x = row
    y = col
    while x < n and y >= 0:
        if board[x][y] == 'Q':
            return False
        x += 1
        y -= 1
 
    return True
    

def solve(col, ans, board, n):
    if col == n:
        addSoln(ans, board, n)
        return
    
    for row in range(n):
        if isSafe(row, col, board, n):
            board[row][col] = 'Q'
            solve(col + 1, ans, board, n)
            board[row][col] = 0

def nQueens(n):
    ans = []
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve(0, ans, board, n)
    return ans

if __name__ == "__main__":
    n = 4
    arr = [[0 for _ in range(n)] for _ in range(n)]
    result = nQueens(n)

    for i in range(len(result)):
        print(f'Solution {i + 1}: ')
        for j in range(0, n*n):
            print(result[i][j], end =" ")
            if (j + 1) % n == 0: print()
        print()