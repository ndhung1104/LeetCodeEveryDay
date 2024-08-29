class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int asciiA[257]{0};
        bool asciiB[257]{0};
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (asciiA[s[i]] == 0)
            {
                if (!asciiB[t[i]])
                {
                    asciiA[s[i]] = t[i];
                    asciiB[t[i]] = 1;
                }
                else
                    return false;
                
            }
            else if (asciiA[s[i]] != t[i])
                return false;
        }

        return true;
        
        return true;
    }
};