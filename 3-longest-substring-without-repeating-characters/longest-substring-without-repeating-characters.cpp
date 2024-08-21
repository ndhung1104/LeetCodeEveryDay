class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int size = s.size();
        int len = 0;
        int end = 0;
        //int ascii[1000]{0};
        unordered_set<char> ascii;
        while (end < size)
        {
            if (ascii.find(s[end]) != ascii.end()) //ascii[s[end]]
            {
                len = max(len, end - start);
                while (s[start] != s[end])
                {
                    ascii.erase(s[start]); //ascii[s[start]] = 0;
                    start++;
                }
                start++;
                end++;
            }
            else
            {
                ascii.insert(s[end]); //ascii[s[end]]++;
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