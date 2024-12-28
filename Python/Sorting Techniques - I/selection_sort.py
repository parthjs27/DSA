
def selection_sort(arr):
    n = len(arr)
    for i in range(0, n-1):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[min_idx], arr[i] = arr[i], arr[min_idx]

    return arr


if __name__ == '__main__':

    arr = [6, 7, 1, 4, 11, 2, 8]
    print("List before sort: ", arr)

    sorted_list = selection_sort(arr)
    print("List after sort: ", sorted_list)

    '''

    Time Complexity:

    Best Case: O(n^2)
    Best Case: O(n^2)
    Worst Case: O(n^2)

    Space Complexity:
    O(1)

    '''
    
    
