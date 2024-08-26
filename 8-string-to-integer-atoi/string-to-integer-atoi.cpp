class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1, pos = 0, len = s.size();
        bool whitespace = 1, checkLeadingZeroes = 1;
        while (pos < len && whitespace)
        {
            if (s[pos] == ' ')
                pos++;
            else
                whitespace = 0;
        }
        if (s[pos] == '-')
        {
            sign = -1;
            pos++;
        }
        else if (s[pos] == '+')
            pos++;

        if (s[pos] < '0' || s[pos] > '9')
            return int(result);
        while (pos < len && checkLeadingZeroes)
        {
            if (s[pos] == '0')
                pos++;
            else
                checkLeadingZeroes = 0;
        }
        int count = 0;
        while (pos < len && count < 11)
        {
            if (s[pos] < '0' || s[pos] > '9')
                break;
            else
            {
                result = result * 10 + (s[pos] - '0');
                pos++;
                count++;
            }
                
        }
        long long maxNum = 2147483647;
        if (sign == 1)
            return int(result > maxNum?maxNum:result);
        else
            return int(result > maxNum + 1?-1*(maxNum + 1): -1*result);

    }
};