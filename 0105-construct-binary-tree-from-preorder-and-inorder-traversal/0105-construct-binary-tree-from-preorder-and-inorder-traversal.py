class Solution:
    def buildTree(self, preorder, inorder):
        if not inorder:
            return None

        root_val = preorder.pop(0)
        root = TreeNode(root_val)

        idx = inorder.index(root_val)

        root.left = self.buildTree(preorder, inorder[:idx])
        root.right = self.buildTree(preorder, inorder[idx + 1:])

        return root