
def merge(arr, low, mid, high):
    temp = []
    left = low
    right = mid + 1
    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1
    while left <= mid:
        temp.append(arr[left])
        left += 1
    while right <= high:
        temp.append(arr[right])
        right += 1
    for i in range(low, high + 1):
        arr[i] = temp [i - low]

def merge_sort(arr, low, high):
    if low >= high:
        return
    mid = (low + high) // 2
    merge_sort(arr, low, mid)
    merge_sort(arr, mid + 1, high)
    merge(arr, low, mid, high)

if __name__ == '__main__':
    arr = [ 6, 24, 12, 11, 2, 1, 5, 3 ]
    n = len(arr)

    print('Array before sort: ', arr)

    merge_sort(arr, 0, n-1)
    print("Array after sort: ", arr)



# Time Complexity:

# Best Case: O(nlogn)
# Average Case: O(nlogn)
# Worst Case: O(nlogn)

# Space Complexity:
# O(n)