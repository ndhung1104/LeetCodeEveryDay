class Solution {
public:
    string compressedString(string word) {
        string ans;
        char a = word[0];
        char count = 1;
        int pos = 1, size = word.size();
        while (pos < size)
        {
            if (a == 0)
            {
                a = word[pos];
                count = 1;
            }
            else if (word[pos] == a)
            {
                if (count < 9)
                    count++;
                else
                {
                    ans += "9";
                    ans += a;
                    a = 0;
                    count = 0;
                    pos--;
                }
            }
            else
            {
                char num = count + '0';
                ans += num;
                ans += a;
                a = word[pos];
                count = 1;
            }
            pos++;
        }
        if (a != 0)
        {
            char num = count + '0';
            ans += num;
            ans += a;
        }

        return ans;
    }
};