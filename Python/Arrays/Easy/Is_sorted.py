
def isSorted(arr, n):
    for i in range(0, n):
        for j in range(i + 1, n):
            if arr[j] < arr[j - 1]: return False
    return True

def isSorted_optimal(arr, n):
    for i in range(1, n):
        if arr[i] < arr[i - 1]: return False
    return True

if __name__ == '__main__':

    arr = [ 1, 2, 3, 4, 5, 6, 7 ]
    n = len(arr)
    result = isSorted_optimal(arr, n)
    print("Already Sorted" if result else "Not Sorted")