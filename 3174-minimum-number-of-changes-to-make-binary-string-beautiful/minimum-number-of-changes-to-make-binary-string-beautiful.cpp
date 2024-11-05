class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            int tmp = s[i * 2] + s[i * 2 + 1] - 2 * '0';
            count += (tmp % 2); 
        }

        return count;
    }
};