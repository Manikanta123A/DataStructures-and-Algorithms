# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []
        targetSum -= root.val

        if not root.left and not root.right:
            if targetSum ==0: 
                return [[root.val]]
            else:
                return []

        result = [] 

        for path in self.pathSum(root.left, targetSum):
            result.append([root.val] + path) 
        for path in self.pathSum(root.right, targetSum):
            result.append([root.val]+path)

        return result