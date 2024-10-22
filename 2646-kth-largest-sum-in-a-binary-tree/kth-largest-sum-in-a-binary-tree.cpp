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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        queue<TreeNode*> treeStack;
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
                q.push(treeSum);
                // cout << q.top() << " " << q.size() <<  endl;
                treeSum = 0;
                while (q.size() > k)
                    q.pop();
            }       
        }
        if (treeSum > 0)
        {
            
            q.push(treeSum);
            treeSum = 0;
            while (q.size() > k)
                q.pop();
        }
        if (q.size() != k)
            return -1;

        return q.top();
    }
};