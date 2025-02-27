
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isSumTree(root):
    if root is None:
        return (True, 0)
    if root.left is None and root.right is None:
        return (root.data, root.data)
    
    leftAns = isSumTree(root.left)
    rightAns = isSumTree(root.right)

    left = leftAns[0]
    right = rightAns[0]
    condn = root.data == leftAns[1] + rightAns[1]

    if left and right and condn:
        return (True, root.data + leftAns[1] + rightAns[1])
    else:
        return (False, 0)

if __name__ == "__main__":

    root = Node(26)
    root.left = Node(10)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(6)
    root.right.right = Node(3)

    root3 = Node(20)
    root3.left = Node(10)
    root3.right = Node(9)
    root3.left.left = Node(4)
    root3.left.right = Node(6)
    root3.right.left = Node(14) # Change it to 4 for SumTree 
    root3.right.right = Node(5)

    if isSumTree(root3)[0]:
        print("Is a SumTree")  # Output: Tree 1 is a SumTree
    else:
        print("Not a SumTree")