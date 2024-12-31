
def largest_element(arr, size):

    # Brute force

    # 1. Sort Elements in acending/descending Order
    # 2. Take the last/first element
    arr.sort()
    return arr[size - 1]

def largest_element_iterative(arr, size):
    max_num = -float("inf")
    i = 0
    while i < size:
        if arr[i] > max_num : 
            max_num = arr[i]
        i += 1
    return max_num

if __name__ == '__main__':
    arr = [ 5, 0, 11, 2, 3, 24, 1 ]
    n = len(arr)

    result = largest_element(arr, n)
    print('Largest Element in array: ', result)

    answer = largest_element_iterative(arr, n)
    print('Largest Element in array: ', answer)