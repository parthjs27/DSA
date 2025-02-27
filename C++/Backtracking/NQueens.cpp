#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addSoln(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{

    // ROW
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // UPPER DIAGONAL
    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    // LOWER DIAGONAL

    x = row;
    y = col;

    while (x < n and y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSoln(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> result = nQueens(n);

    // result = {
    //     {0,1,0,0,  0,0,0,1,  1,0,0,0,  0,0,1,0},  // Solution 1
    //     {0,0,1,0,  1,0,0,0,  0,0,0,1,  0,1,0,0}   // Solution 2
    // };
    

    int solCount = 1;
    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << solCount++ << ":\n";
        for (int j = 0; j < n * n; j++) {
            cout << result[i][j] << " ";
            if ((j + 1) % n == 0) cout << endl;  // Print row-wise
        }
        cout << endl;
    }
    return 0;
}