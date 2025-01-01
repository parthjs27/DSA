#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force
bool isSorted(vector<int> arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[j - 1]) {         
                return false;
            }
        }
    }
    return true;
}

// Time Complexity : O(n^2)

// Optimal Solution
bool isSorted_optimal(vector<int> arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}

// Time Complexity : O(n)

int main(){

    vector<int> arr = { 1, 2, 3, 4, 9, 6, 7 };
    int n = arr.size();

    bool result = isSorted_optimal(arr, n-1);

    if(result){
       cout << "Array is sorted";
    }else{
       cout << "Array is not sorted";
    }
    
    return 0;
}