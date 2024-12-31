#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int second_largest_element(vector<int> arr, int size){

    if (size < 2) return -1;

    sort(arr.begin(), arr.end());

    int largest = arr[size - 1];
    for (int i = size - 2; i >= 0; i--){
        if(arr[i] < largest){
            return arr[i];
        }
    }
    return -1;

    // Time Complexity : O(nlogn)
    // Space Complexity : O(1)
}

int second_largest_element_optimal(vector<int> arr, int size){
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < size; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second_largest){
            second_largest = arr[i];
        }
    }
    return second_largest;

    // Time Complexity : O(n)
    // Space Complexity : O(1)
}

int main(){

    vector<int> arr = { 5, 0, 11, 2, 3, 24, 1 };
    int n = arr.size();

    int result = second_largest_element_optimal(arr, n);
    cout << "Second Largest element: " << result << endl;

    return 0;
}