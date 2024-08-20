class Solution {
public:
    int getNum(char c)
    {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        return 1000;
    }
    int romanToInt(string s) {
        int count = 0, pos = 0;
        while (pos < s.size())
        {
            if (pos + 1 < s.size())
            {
                if (s[pos] == 'I')
                    if (s[pos + 1] == 'V')
                    {
                        count += 4;
                        pos += 2;
                    }
                    else if (s[pos + 1] == 'X')
                    {
                        count += 9;
                        pos += 2;
                    }
                    else
                    {
                        count += getNum(s[pos]);
                        pos++;
                    }
                else if (s[pos] == 'X')
                    if (s[pos + 1] == 'L')
                    {
                        count += 40;
                        pos += 2;
                    }
                    else if (s[pos + 1] == 'C')
                    {
                        count += 90;
                        pos += 2;
                    }
                    else
                    {
                        count += getNum(s[pos]);
                        pos++;
                    }
                else if (s[pos] == 'C')
                    if (s[pos + 1] == 'D')
                    {
                        count += 400;
                        pos += 2;
                    }
                    else if (s[pos + 1] == 'M')
                    {
                        count += 900;
                        pos += 2;
                    }
                    else
                    {
                        count += getNum(s[pos]);
                        pos++;
                    }
                else
                {
                    count += getNum(s[pos]);
                    pos++;
                }
            }
            else
            {
                count += getNum(s[pos]);
                pos++;
            }

            
        }
        return count;
    }
};