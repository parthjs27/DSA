
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        j = i
        while (j > 0) and (arr[j - 1] > arr[j]):
            arr[j - 1], arr[j] = arr[j], arr[j - 1]
            j -= 1
    return arr

if __name__ == '__main__':

    arr = [6, 7, 1, 4, 11, 2, 8]
    print('Array before sort: ', arr)

    sorted_list = insertion_sort(arr)
    print('Array after sort: ', sorted_list)


# Time Complexity:

# Best Case: O(n)
# Average Case: O(n^2)
# Worst Case: O(n^2)

# Space Complexity:
# O(1)