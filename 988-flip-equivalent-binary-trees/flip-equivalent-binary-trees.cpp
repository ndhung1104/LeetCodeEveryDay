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
    bool checkNode(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 && root2 && root1->val == root2->val)
            return true;
        
        return false;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> treeQueue1, treeQueue2;
        if (!checkNode(root1, root2))
            return false;
        if (!root1)
            return true;
        treeQueue1.push(root1);
        treeQueue2.push(root2);
        
        while (treeQueue1.size() > 0)
        {
            TreeNode* tmp1 = treeQueue1.front();
            TreeNode* tmp2 = treeQueue2.front();
            treeQueue1.pop();
            treeQueue2.pop();
            TreeNode* left1, *left2, *right1, *right2;
            left1 = tmp1->left;
            left2 = tmp2->left;
            right1 = tmp1->right;
            right2 = tmp2->right;
            if (checkNode(left1, left2) && checkNode(right1, right2))
            {
                if (left1)
                {
                    treeQueue1.push(left1);
                    treeQueue2.push(left2);
                }
                if (right1)
                {
                    {
                        treeQueue1.push(right1);
                        treeQueue2.push(right2);
                    }
                }
            }
            else if (checkNode(left1, right2) && checkNode(right1, left2))
            {
                if (left1)
                {
                    treeQueue1.push(left1);
                    treeQueue2.push(right2);
                }
                if (right1)
                {
                    {
                        treeQueue1.push(right1);
                        treeQueue2.push(left2);
                    }
                }
            }
            else
                return false;
        }

        return true;
    }
};