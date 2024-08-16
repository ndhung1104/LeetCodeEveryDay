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
// void addHead(ListNode* &pHead, int key)
//     {
//         ListNode* pTemp = pHead;
//         pHead = new ListNode;
//         pHead->val = key;
//         pHead->next = pTemp;
//         return;
//     }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pos = 1, num = 0, remainder;
        ListNode* pTail;
        ListNode* pTempHead = new ListNode(0);
        pTail = pTempHead;
        while (l1 && l2)
        {
            num += l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            remainder = num % 10;
            // cout << remainder << " ";
            num = num / 10;
            ListNode* pTemp = new ListNode(remainder);
            pTail->next = pTemp;
            pTail = pTail->next;
            // pHead->val = remainder;
            // pHead->next = pTemp;
        }
        // cout << 1 << endl;
        if (l1)
            while (l1)
            {
                num += l1->val;
                l1 = l1->next;
                remainder = num % 10;
                num = num / 10;
                ListNode* pTemp = new ListNode(remainder);
                pTail->next = pTemp;
                pTail = pTail->next;
            }
        else
            while (l2)
            {
                num += l2->val;
                l2 = l2->next;
                remainder = num % 10;
                num = num / 10;
                ListNode* pTemp = new ListNode(remainder);
                pTail->next = pTemp;
                pTail = pTail->next;
            }
        // cout << 1 << endl;
        while (num > 0)
        {
            remainder = num % 10;
            num = num / 10;
            ListNode* pTemp = new ListNode(remainder);
            pTail->next = pTemp;
            pTail = pTail->next;
        }
        // cout << 1 << endl;
        return pTempHead->next;
    }
};