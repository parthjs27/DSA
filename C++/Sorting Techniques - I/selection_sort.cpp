#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr){
    int n = arr.size();
    int min_idx;
    for (int i = 0; i < n - 1; i++){
        min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main(){                               
    //                  0  1  2  3   4  5  6
    vector<int> arr = { 6, 7, 1, 4, 11, 2, 8 };
    cout << "Array before sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    
    cout << "Array after sort: " << endl;
    selection_sort(arr);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity:

// Best Case: O(n^2)
// Average Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity:
// O(1)