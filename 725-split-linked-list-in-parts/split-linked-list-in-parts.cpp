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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* pTemp = head;
        while (pTemp)
        {
            count++;
            pTemp = pTemp->next;
        }
        vector<ListNode*> ans;
        if (count <= k)
        {
            while (k > 0)
            {
                if (count > 0)
                {
                    pTemp = head;
                    head = head->next;
                    pTemp->next = nullptr;
                    ans.push_back(pTemp);
                    count--;
                    k--;
                }
                else
                {
                    ans.push_back(nullptr);
                    k--;
                }
            }
        }
        else
        {
            while (count > 0)
            {
                int numPush = count / k;
                if (count % k != 0)
                    numPush++;
                ans.push_back(head);
                for (int i = 0; i < numPush; i++)
                {
                    pTemp = head;
                    head = head->next;
                }
                pTemp->next = nullptr;
                count = count - numPush;
                k--;
            }
        }

        return ans;
    }
};