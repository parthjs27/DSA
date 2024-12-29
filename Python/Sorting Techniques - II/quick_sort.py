
def partition(arr, low, high):
    pivot = arr[low]
    l = low
    r = high

    while l < r:
        while (arr[l] <= pivot) and (l <= high - 1):
            l += 1
        while (arr[r] > pivot) and (r >= low + 1):
            r -= 1
        if l < r:
            arr[l], arr[r] = arr[r], arr[l]
    arr[low], arr[r] = arr[r], arr[low]
    return r

def quick_sort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)
        quick_sort(arr, low, p - 1)
        quick_sort(arr, p + 1, high)

if __name__ == '__main__':
    arr = [ 6, 7, 1, 4, 11, 2, 8, 10 ]
    n = len(arr)

    print('Array before sort: ', arr)

    quick_sort(arr, 0, n-1)
    print("Array after sort: ", arr)


# Time Complexity:

# Best Case: O(nlogn)
# Average Case: O(nlogn)
# Worst Case: O(n^2)

# Space Complexity:
# O(1) + O(n) { auxillary stack }