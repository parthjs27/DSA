
def recurisive_bubble_sort(arr, n):
    # base case
    if n == 1: return
    isSwapped = False
    for i in range(0, n - 1):
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
            isSwapped = True
        if not isSwapped:
            return

    recurisive_bubble_sort(arr, n - 1)


if __name__ == '__main__':
    arr = [ 6, 24, 12, 11, 2, 1, 5, 3 ]
    n = len(arr)

    print('Array before sort: ', arr)

    recurisive_bubble_sort(arr,n)
    print("Array after sort: ", arr)

# Time Complexity:

# Best Case: O(n)
# Average Case: O(n^2)
# Worst Case: O(n^2)

# Space Complexity:
# O(n) Due to stack in recursion