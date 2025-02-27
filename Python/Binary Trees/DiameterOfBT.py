
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def DiameterOptimized(root):
    if root is None:
        return (0, 0)
    left = DiameterOptimized(root.left)
    right = DiameterOptimized(root.right)

    diameter = max(left[0], right[0], left[1] + right[1] + 1)
    height = max(left[1], right[1]) + 1

    return diameter, height


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)
    root.left.right.left = Node(7)
    root.right.right.left = Node(8)
    root.right.right.left.left = Node(9)

    diameter, height = DiameterOptimized(root)
    print('Diameter of BT is: ', diameter)
