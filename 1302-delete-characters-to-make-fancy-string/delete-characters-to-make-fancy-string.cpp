class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;
        char curChar = s[0];
        ans += curChar;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == curChar)
            {
                if (count < 2)
                {
                    count++;
                    ans += curChar;
                }
            }
            else
            {
                count = 1;
                curChar = s[i];
                ans += curChar;
            }
        }
        return ans;
    }
};