# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_path = float("-inf")
        def f(node):
            nonlocal max_path
            if node is None:
                return 0
            left = max(f(node.left),  0)
            right = max(f(node.right), 0)
            
            curr = node.val + left + right
            max_path = max(max_path, curr)
            
            return node.val + max(left, right)
        f(root)
        return max_path