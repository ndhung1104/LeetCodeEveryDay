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

//  struct TreeNode {
//       int val;
//       int height;
//       bool isMainTree;
//       int otherBranchHeight;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
    int treeHeight[100001]{0};
    int maxHeightAfterRemoval[100001]{0};
    int getHeight(TreeNode* root)
    {
        if (root == nullptr)
            return -1;
        int h = max(getHeight(root->left), getHeight(root->right)) + 1;
        treeHeight[root->val] = h;
        return h;
    }
    void getMaxHeightRightTree(TreeNode* root, int maxHeight)
    {
        if (root)
        {
            maxHeightAfterRemoval[root->val] = maxHeight;
            getMaxHeightRightTree(root->left, maxHeight);
            getMaxHeightRightTree(root->right, maxHeight);
        }
    }
    void getMaxHeightLeftTree(TreeNode* root, int curLevel, int rightTreeHeight)
    {
        if (root)
        {
            int rightHeight = -1, leftHeight = -1;
            if (root->left)
                leftHeight = treeHeight[root->left->val];
            if (root->right)
                rightHeight = treeHeight[root->right->val];
            if (root->left)
            {
                maxHeightAfterRemoval[root->left->val] = max(rightTreeHeight, rightHeight + curLevel + 1);
                getMaxHeightLeftTree(root->left, curLevel + 1, maxHeightAfterRemoval[root->left->val]);
            }
            if (root->right)
            {
                maxHeightAfterRemoval[root->right->val] = max(rightTreeHeight, leftHeight + curLevel + 1);
                getMaxHeightLeftTree(root->right, curLevel + 1, maxHeightAfterRemoval[root->right->val]);
            }
        }
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int tmp = getHeight(root);
        if (root->left == nullptr || (root->right != nullptr && treeHeight[root->right->val] > treeHeight[root->left->val]))
            swap(root->left, root->right);
        getMaxHeightRightTree(root->right, treeHeight[root->val]);
        
        
        if (root->right == nullptr)
            maxHeightAfterRemoval[root->left->val] = 0;
        else
            maxHeightAfterRemoval[root->left->val] = treeHeight[root->right->val] + 1;
        
        getMaxHeightLeftTree(root->left, 1, maxHeightAfterRemoval[root->left->val]);
        for (int i = 0; i < queries.size(); i++)
            queries[i] = maxHeightAfterRemoval[queries[i]];
        
        return queries;
    }
};