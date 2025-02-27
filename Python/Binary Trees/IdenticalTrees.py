class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def areIdentical(r1, r2):
    if r1 is None and r2 is None:
        return True
    
    if r1 is None or r2 is None:
        return False

    left = areIdentical(r1.left, r2.left)
    right = areIdentical(r1.right, r2.right)
    value = r1.data == r2.data

    if left and right and value:
        return True
    else:
        return False
    
if __name__ == "__main__":
    r1 = Node(1)
    r1.left = Node(2)
    r1.right = Node(3)

    r2 = Node(1)
    r2.left = Node(2)
    r2.right = Node(3)

    if areIdentical(r1, r2):
        print('Trees are identical')
    else:
        print('Trees are not identical')
    