class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);
        int remainder = 0;
        string ans;

        for (int i = 0; i < b.size(); i++)
        {
            
            int cal = a[a.size() - i - 1] + b[b.size() - i - 1] - 2 * '0' + remainder;
            // cout << a[i] << " " << b[i] << " " << cal << " " << remainder << endl;
            remainder = 0;
            if (cal == 0)
                ans = "0" + ans;
            else if (cal == 1)
                ans = "1" + ans;
            else if (cal == 2)
            {
                ans = "0" + ans;
                remainder = 1;
            }
            else
            {
                ans = "1" + ans;
                remainder = 1;
            }
        }

        for (int i = a.size() - b.size() - 1; i > -1; i--)
        {
            if (remainder)
            {
                if (a[i] == '0')
                {
                    ans = "1" + ans;
                    remainder = 0;
                }
                else
                {
                    ans = "0" + ans; 
                }
            }
            else
                ans = a[i] + ans;
        }
        if (remainder)
            ans = "1" + ans;
        
        return ans;
    }
};