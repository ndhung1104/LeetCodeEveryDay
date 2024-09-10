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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode* pReturn = head;
        ListNode* pNext = head->next;
        while (pNext)
        {
            int newGcd = gcd(head->val, pNext->val);
            head->next = new ListNode(newGcd, pNext);
            head = head->next->next;
            pNext = head->next;
        }

        return pReturn;
    }
};