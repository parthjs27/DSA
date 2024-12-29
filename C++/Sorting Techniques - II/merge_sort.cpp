#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){

    vector<int> arr = { 6, 7, 1, 4, 11, 2, 8 }; 
    int n = arr.size();

    cout << "Array before sort: " << endl;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    cout << "Array after sort: " << endl;
    merge_sort(arr, 0, n-1);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}

// Time Complexity:

// Best Case: O(nlogn)
// Best Case: O(nlogn)
// Worst Case: O(nlogn)

// Space Complexity:
// O(n)