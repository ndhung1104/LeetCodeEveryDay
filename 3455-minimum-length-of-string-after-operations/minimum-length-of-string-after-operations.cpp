class Solution {
public:
    int minimumLength(string s) {
        int count[300]{0};
        int l = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            if (count[s[i]] == 3)
            {
                count[s[i]] = 1;
                l -= 2;
            }
        }

        return l; 
    }
};