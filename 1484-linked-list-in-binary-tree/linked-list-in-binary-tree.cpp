/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathRecursion1(ListNode* head, TreeNode* root)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (head->val == root->val)   
            return (isSubPathRecursion1(head->next, root->left) || isSubPathRecursion1(head->next, root->right));
        
        return false;
    }

    bool isSubPathRecursion(ListNode* head, TreeNode* root)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
            
        return (isSubPathRecursion1(head, root) || isSubPathRecursion(head, root->left) || isSubPathRecursion(head, root->right));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathRecursion(head, root);
    }
};