class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size(), haystackSize = haystack.size();
        for (int i = 0; i < haystackSize - needleSize + 1; i++)
        {
            string tmp = haystack.substr(i, needleSize);
            if (tmp == needle)
                return i;
        }

        return -1;
    }
};