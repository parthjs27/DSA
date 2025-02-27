#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n){
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0) && (arr[newx][newy] == 1)){
        return true;
    }else{
        return false;
    }
}

void solve(int x, int y, vector<string> &ans, vector<vector<int>> &arr, vector<vector<bool>> &visited, int n,string path){
    
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if(isSafe(x + 1, y, visited , arr, n)){
        solve(x + 1, y, ans, arr, visited, n, path + 'D');
    }
    
    // Left
    if(isSafe(x, y - 1, visited , arr, n)){
        solve(x, y - 1, ans, arr, visited, n, path + 'L');
    }

    // Right
    if(isSafe(x, y + 1, visited , arr, n)){
        solve(x, y + 1, ans, arr, visited, n, path + 'R');
    }

    // Up
    if(isSafe(x - 1, y, visited , arr, n)){
        solve(x - 1, y, ans, arr, visited, n, path + 'U');
    }
    
    visited[x][y] = 0;
}

vector<string> RatInaMaze(vector<vector<int>>& arr, int n){
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    solve(0, 0, ans, arr, visited, n, path);
    return ans;
}

int main(){

    vector<vector<int>> arr = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };

    int n = arr.size();

    for (int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    vector<string> result = RatInaMaze(arr, n);
    
    for(const string &path: result){
        cout << path << endl;
    }
    
    return 0;
}