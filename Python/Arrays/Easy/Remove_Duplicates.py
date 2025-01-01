
from typing import List

def remove_duplicates(arr: List[int], n) -> int:
    i = 0
    for j in range(1, n):
        if arr[i] != arr[j]:
            i += 1
            arr[i] = arr[j]
    return i + 1
    
if __name__ == '__main__':

    arr = [ 1, 1, 1, 2, 2, 3, 3, 3, 4 ]
    n = len(arr)
    print("Array before: ", arr)

    result = remove_duplicates(arr, n)
    print("Array after: ")
    for i in range(result):
        print(arr[i], end=" ")