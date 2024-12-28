#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i <= n - 1; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){

    vector<int> arr = { 6, 7, 1, 4, 11, 2, 8 };

    cout << "Array before sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    
    cout << "Array after sort: " << endl;
    insertion_sort(arr);
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
// O(1)