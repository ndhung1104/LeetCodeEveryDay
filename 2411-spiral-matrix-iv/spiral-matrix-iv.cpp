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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int right = n - 1, left = 0, down = m - 1, up = 1;
        int direction = 0, i = 0, j = 0; // 0 = right, 1 = down, 2 = left, 3 = up
        while (head)
        {
            ans[i][j] = head->val;
            head = head->next;
            if (direction == 0) // right
            {
                if (j == right)
                {
                    direction = 1;
                    i++;
                    right--;
                }
                else
                    j++;
            }
            else if (direction == 1) // down
            {
                if (i == down)
                {
                    direction = 2;
                    j--;
                    down--;
                }
                else
                    i++;
            }
            else if (direction == 2) // left
            {
                if (j == left)
                {
                    direction = 3;
                    i--;
                    left++;
                }
                else
                    j--;
            }
            else
            {
                if (i == up)
                {
                    direction = 0;
                    j++;
                    up++;
                }
                else
                    i--;
            }

        }
        return ans;
    }
};