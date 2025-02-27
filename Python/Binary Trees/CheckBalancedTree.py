
class Node:
    def __init__(self, data):
        self.data = data
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

def isBalancedTree(root):
    if root is None:
        return True
    leftTree = isBalancedTree(root.left)
    rightTree = isBalancedTree(root.right)

    value = abs(treeHeight(root.left) - treeHeight(root.right)) <= 1

    if(leftTree and rightTree and value):
        return True
    else:
        return False
    
def isBalancedTreeOptimized(root):
    if root is None:
        return (True, 0)
    leftTree = isBalancedTreeOptimized(root.left)
    rightTree = isBalancedTreeOptimized(root.right)

    leftBalanced = leftTree[0]
    rightBalanced = rightTree[0]
    value = abs(leftTree[1] - rightTree[1]) <= 1
   
    isBalanced = leftBalanced and rightBalanced and value
    height = max(leftTree[1], rightTree[1]) + 1

    return (isBalanced, height)


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.left.left = Node(5)

    balance, height = isBalancedTreeOptimized(root)

    if balance:
        print('Tree is balanced')
    else:
        print('Tree is not balanced')

