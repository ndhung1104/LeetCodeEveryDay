class Solution {
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
        
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string count;
        int minLen = strs[0].size();
        for (int i = 1; i < size; i++)
            minLen = min(minLen, strs[i].size());
        for (int i = 0; i < minLen; i++)
        {
            for (int j = 0; j < size - 1; j++)
                if (strs[j][i] != strs[j + 1][i])
                {
                    i = minLen;
                    break;
                }
            if (i != minLen)
                count += strs[0][i];
        }
        return count;
    }
};