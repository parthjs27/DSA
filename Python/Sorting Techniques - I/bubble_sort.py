
def bubble_sort(arr):
    n = len(arr)
    for i in range(0, n-1):
        isSwapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                isSwapped = True
        if not isSwapped:
            break   
    return arr

if __name__ == '__main__':

    arr = [6, 7, 1, 4, 11, 2, 8]
    print('Array before sort: ', arr)

    sorted_list = bubble_sort(arr)
    print('Array after sort: ', sorted_list)


# Time Complexity:

# Best Case: O(n)
# Average Case: O(n^2)
# Worst Case: O(n^2)

# Space Complexity:
# O(1)