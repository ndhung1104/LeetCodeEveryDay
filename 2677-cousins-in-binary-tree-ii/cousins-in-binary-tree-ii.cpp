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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> treeStack;
        vector<long long> q;
        treeStack.push(root);
        treeStack.push(nullptr);
        long long treeSum = 0;
        while (treeStack.size() > 0)
        {
            TreeNode* pTop = treeStack.front();
            treeStack.pop();
            if (pTop)
            {
                treeSum += pTop->val;
                if (pTop->left)
                    treeStack.push(pTop->left);
                if (pTop->right)
                    treeStack.push(pTop->right);
            }
            else if (treeStack.size() > 0)
            {
                
                treeStack.push(nullptr);
                q.push_back(treeSum);
                treeSum = 0;
            }       
        }
        if (treeSum)
            q.push_back(treeSum);
        
        // for (int i = 0; i < q.size(); i++)
        //     cout << q[i] << " ";
        while (treeStack.size() > 0)
            treeStack.pop();
        int level = 1;
        treeStack.push(root);
        treeStack.push(nullptr);
        root->val = 0;
        while (treeStack.size() > 0)
        {
            TreeNode* pTop = treeStack.front();
            treeStack.pop();
            if (pTop)
            {
                if (pTop->left || pTop->right)
                {
                    long long tmp = q[level];
                    if (pTop->left)
                    {
                        tmp -= pTop->left->val;
                        treeStack.push(pTop->left);
                    }
                        
                    if (pTop->right)
                    {
                        tmp -= pTop->right->val;
                        treeStack.push(pTop->right);
                    }
                    if (pTop->left)
                        pTop->left->val = tmp;
                    if (pTop->right)
                        pTop->right->val = tmp;
                }
            }
            else if (treeStack.size() > 0)
            {
                treeStack.push(nullptr);
                level++;
            }       
        }
        return root;
    }
};

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
