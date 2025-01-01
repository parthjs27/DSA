
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> &arr, int n){

    int i = 0;
    for (int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return (i + 1);
}

int main(){

    vector<int> arr = { 1, 1, 1, 2, 2, 3, 3, 3, 4 };
    int n = arr.size();

    int k = remove_duplicates(arr, n);
    cout << k << endl;
    
    for(int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    return 0;
}