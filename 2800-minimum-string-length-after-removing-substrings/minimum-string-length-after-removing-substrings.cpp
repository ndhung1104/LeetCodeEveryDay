class Solution {
public:
    int minLength(string s) {
        int len = s.size();
        int pos = 0;
        while (pos < len - 1)
        {
            if ((s[pos] == 'A' && s[pos + 1] == 'B') || (s[pos] == 'C' && s[pos + 1] == 'D'))
            {
                string tmp = s.substr(0, pos) + s.substr(pos + 2);
                s = tmp;
                len = s.size();
                if (pos > 0)
                    pos--;
            }
            else
                pos++;
            
        }

        return s.size();
    }
};