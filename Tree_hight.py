class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def height(self, root):
        if root is None:
            return -1
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        return 1 + max(left_height, right_height)

def build_tree(nodes_info):
    nodes = {}
    
    for val, left_val, right_val in nodes_info:
        if val not in nodes:
            nodes[val] = Node(val)
        node = nodes[val]
        
        if left_val != -1:
            if left_val not in nodes:
                nodes[left_val] = Node(left_val)
            node.left = nodes[left_val]
        
        if right_val != -1:
            if right_val not in nodes:
                nodes[right_val] = Node(right_val)
            node.right = nodes[right_val]
    
    # root is the first node given
    root_val = nodes_info[0][0]
    return nodes[root_val]

# Read input
n = int(input("Enter number of nodes: "))
nodes_info = []
print("Enter node_value left_child_value right_child_value (-1 if no child):")
for _ in range(n):
    val, left_val, right_val = map(int, input().split())
    nodes_info.append((val, left_val, right_val))

root = build_tree(nodes_info)

sol = Solution()
print(sol.height(root))
