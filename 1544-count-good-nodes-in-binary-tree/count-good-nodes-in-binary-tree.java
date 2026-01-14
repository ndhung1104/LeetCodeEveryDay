/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int recr(TreeNode root, int val) {
        if (root == null)
            return 0;
        
        if (root.val >= val)
            return (1 + recr(root.left, root.val) + recr(root.right, root.val));
        
        return (recr(root.left, val) + recr(root.right, val));
    }

    public int goodNodes(TreeNode root) {
        if (root == null)
            return 0;

        return recr(root, root.val);
    }
}