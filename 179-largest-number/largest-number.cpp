class Solution {
public:
    static bool compareNumber(int a, int b)
    {
        string aS = to_string(a);
        string bS = to_string(b);
        string ab = aS + bS, ba = bS + aS;
        // cout << a << " " << b << " " << ab << " " << ba << endl;
        for (int i = 0; i < ab.size(); i++)
        {
            if (ab[i] > ba[i])
                return true;
            if (ab[i] < ba[i])
                return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<vector<int>> tmp(11, vector<int>());
        vector<int> ans;
        string largestNum;
        bool allZeroes = true;

        for (int i = 0; i < nums.size(); i++)
        {
            int tmpNum = nums[i];
            // cout << nums[i] << " ";
            while (tmpNum > 9)
                tmpNum = tmpNum / 10;
            tmp[tmpNum].push_back(nums[i]);
        }
        // cout << endl;

        for (int i = 9; i >= 0; i--)
        {
            if (tmp[i].size() > 0)
            {
                if (i != 0)
                {
                    allZeroes = false;
                    sort(tmp[i].begin(), tmp[i].end(), compareNumber);
                }
                for (int j = 0; j < tmp[i].size(); j++)
                {
                    // cout << tmp[i][j] << " ";
                    ans.push_back(tmp[i][j]);
                }
                // cout << endl;
                    
            }   
        }
            

        if (allZeroes)
            return "0";


        for (int i = 0; i < ans.size(); i++)
            largestNum += to_string(ans[i]);
        
        return largestNum;
    }
};