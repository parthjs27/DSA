
class Node:
    def __init__(self, data):
        self.data= data
        self.left = None
        self.right = None
    
def treeHeight(root):
    if root is None:
        return 0
    height = 0
    q = [(root, 0)]

    while q:
       node, level = q.pop(0)
       height = max(height, level)
       if node.left:
           q.append((node.left, level+1))
       if node.right:
           q.append((node.right, level+1))
    return height + 1

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

    height = treeHeight(root)
    print('Height of BT: ', height)
