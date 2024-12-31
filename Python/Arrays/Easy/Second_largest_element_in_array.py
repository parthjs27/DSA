
def second_largest_element(arr, n):
    largest = float("-inf")
    second_largest = float("-inf")
    for i in range(0, n-1):
        if arr[i] > largest:
            second_largest = largest
            largest = arr[i]
        elif arr[i] < largest and arr[i] > second_largest:
            second_largest = arr[i]
    return second_largest

if __name__ == '__main__':
    arr = [ 5, 0, 11, 2, 3, 24, 1 ]
    n = len(arr)

    result = second_largest_element(arr, n)
    print('Largest Element in array: ', result)

# Time Complexity : O(n)
# Space Complexity : O(1)