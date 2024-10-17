class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        // cout << "Step 1 \n";
        int i;
        for (i = 0; i < s.size() - 1; i++)
            if (s[i] < s[i + 1])
                break;
        
        if (i == s.size() - 1)
            return num;
        char maxNum = s[i + 1];
        int maxPos = i + 1;
        // cout << "Step 1 \n";
        for (int j = maxPos + 1; j < s.size(); j++)
            if (maxNum <= s[j])
            {
                maxNum = s[j];
                maxPos = j;
            }
        
        // cout << "Step 1 \n";
        for (int j = 0; j < i + 1; j++)
            if (s[j] < maxNum)
            {
                char tmp = s[j];
                s[j] = maxNum;
                s[maxPos] = tmp;
                break;
            }
        return stoi(s);
    }
};