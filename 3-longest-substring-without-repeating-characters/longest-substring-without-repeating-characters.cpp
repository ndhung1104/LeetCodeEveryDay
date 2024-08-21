class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int size = s.size();
        int len = 0;
        int end = 0;
        int ascii[1000]{0};
        while (end < size)
        {
            if (ascii[s[end]])
            {
                len = max(len, end - start);
                while (s[start] != s[end])
                {
                    ascii[s[start]] = 0;
                    start++;
                }
                start++;
                end++;
            }
            else
            {
                ascii[s[end]]++;
                end++;
                if (end == size)
                {
                    len = max(len, end - start);
                    break;
                }
            }
        }
        return len;
    }
};