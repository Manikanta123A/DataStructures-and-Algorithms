# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.ans = 0 
        def dfs(curr):
            if not curr:
                return 0,0 
            left_sum , left_count = dfs(curr.left)
            right_sum, right_count = dfs(curr.right) 

            total_sum = curr.val+ left_sum + right_sum
            total_count = 1+ left_count + right_count 

            avg = total_sum // total_count 
            if curr.val == avg:
                self.ans +=1 
            return total_sum , total_count 
        dfs(root)
        return self.ans