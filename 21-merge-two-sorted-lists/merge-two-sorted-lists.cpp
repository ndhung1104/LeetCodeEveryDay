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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pTemp = new ListNode();
        ListNode* pHead = pTemp;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                pHead->next = new ListNode(list1->val);
                list1 = list1->next;
            }  
            else
            {
                pHead->next = new ListNode(list2->val);
                list2 = list2->next;
            }

            pHead = pHead->next;
        }
        if (list1)
            while (list1)
            {
                pHead->next = new ListNode(list1->val);
                list1 = list1->next;
                pHead = pHead->next;
            }
        else if (list2)
            while (list2)
            {
                pHead->next = new ListNode(list2->val);
                list2 = list2->next;
                pHead = pHead->next;
            }
        
        return pTemp->next;
    }
};