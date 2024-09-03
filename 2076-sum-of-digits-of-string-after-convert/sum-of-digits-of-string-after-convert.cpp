class Solution {
public:
    int getLucky(string s, int k) {
        int strLen = s.size(), sum = 0;
        for (int i = 0; i < strLen; i++)
        {
            int tmp = s[i] - 'a' + 1;
            while (tmp > 0)
            {
                sum += tmp % 10;
                tmp = tmp / 10;
            }
        }
        k--;
        while (k > 0)
        {
            int tmp = 0;
            while (sum > 0)
            {
                tmp += sum % 10;
                sum = sum / 10;
            }
            sum = tmp;
            k--;
        }

        return sum;
    }
};