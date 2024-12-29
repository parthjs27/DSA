#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int l = low;
    int r = high;

    while(l < r){
        while(arr[l] <= pivot && l <= high - 1) {
            l++;
        }
    
        while(arr[r] > pivot && r >= low + 1){
            r--;
        } 
        if (l < r){
            swap(arr[l], arr[r]);
        }
    }
    swap(arr[low], arr[r]);
    return r;
}

void quick_sort(vector<int> &arr, int low, int high){
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
} 

int main(){

    vector<int> arr = { 6, 7, 1, 4, 11, 2, 8, 10 }; 
    int n = arr.size();

    cout << "Array before sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    cout << "Array after sort: " << endl;
    quick_sort(arr, 0, n-1);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity:

// Best Case: O(nlogn)
// Average Case: O(nlogn)
// Worst Case: O(n^2)

// Space Complexity:
// O(1) + O(n) { auxillary stack }