#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(vector<int> &arr, int n){
    if (n == 1) return;
    bool isSwapped = false;
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1]){
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            isSwapped = true;
        } 
    }
    if(!isSwapped) return;
    recursive_bubble_sort(arr, n - 1);
}

int main(){

    vector<int> arr = { 6, 7, 1, 4, 11, 2, 8, 0, 2, 5 }; 
    // vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int n = arr.size();

    cout << "Array before sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    recursive_bubble_sort(arr, n);

    cout << "Array after sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity:

// Best Case: O(n)
// Best Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity:
// O(n) Due to stack in recursion