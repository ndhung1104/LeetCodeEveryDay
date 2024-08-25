/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        LRN(root, ans);

        return ans;
    }
private:
    void LRN(TreeNode* root, vector<int> &a)
    {
        if (root)
        {
            LRN(root->left, a);
            LRN(root->right, a);
            a.push_back(root->val);
        }
    }
};