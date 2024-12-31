#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int largest_element(vector<int> &arr, int size){
    
    // Brute force

    // 1. Sort Elements in acending/descending Order
    // 2. Take the last/first element

    sort(arr.begin(), arr.end());
    return arr[size - 1];

    // Time Complexity : O(nlogn)
    // Space Complexity : O(1)

}

int largest_element_iterative(vector<int> arr, int size){

    // Iterative Approach

    // 1. Set max = min(integer value) i.e. INT_MIN
    // 2. If max > element of the array update max to that element

    int max = INT_MIN;
    int i = 0;
    while(i < size){
        if (arr[i] > max) max = arr[i];
        i++;
    }
    return max;
}

int main(){

    vector<int> arr = { 5, 0, 11, 2, 3, 24, 1 };
    int n = arr.size();

    int result = largest_element(arr, n);
    cout << "Largest element: " << result << endl;

    int answer = largest_element_iterative(arr, n);
    cout << "Largest element: " << answer << endl;
    return 0;
}