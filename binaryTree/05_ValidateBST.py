
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def isValidBST(self, root: TreeNode) -> bool:
        
        import math

        def validate(node, low= -math.inf, high=math.inf):
# Empty trees are valid BST's
            if not node:
                return True
# The current node's value must be between low and high
            if node.val <= low or node.val >= high:
                return False

            return (validate(node.left, low, node.val) and 
                                        validate(node.right, node.val, high))

        return validate(root)

