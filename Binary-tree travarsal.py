class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree():
    val = int(input())
    if val == -1:
        return None
    node = Node(val)
    node.left = build_tree()
    node.right = build_tree()
    return node

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")

print("Enter nodes in preorder (-1 for NULL):")
root = build_tree()

print("Inorder:")
inorder(root)
print("\nPreorder:")
preorder(root)
print("\nPostorder:")
postorder(root)
