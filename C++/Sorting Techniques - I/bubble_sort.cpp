#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr){

    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
    int isSorted = 0;
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 1;
            }
        }

    // Early check is array is already sorted
        if(isSorted == 0){
            break;
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
    bubble_sort(arr);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}

// Time Complexity:

// Best Case: O(n)
// Average Case: O(n^2)
// Worst Case: O(n^2)

// Space Complexity:
// O(1)