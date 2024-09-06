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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> numsArray(100010, 0);
        int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++)
            numsArray[nums[i]] = 1;
        
        ListNode* pHeadTemp = new ListNode();
        pHeadTemp->next = head;

        head = pHeadTemp;
        while (head && head->next)
        {
            if (numsArray[head->next->val])
            {
                ListNode* pTemp = head->next;
                head->next = head->next->next;
                delete pTemp;
            }
            else
                head = head->next;
        }

        return pHeadTemp->next;
    }
};