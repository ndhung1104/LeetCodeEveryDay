class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int size = nums.size();
        int remainder = 0;
        for (int i = 0; i < size; i++)
            remainder = (remainder + nums[i] % p) % p;
        int target = remainder;

        if (target == 0)
            return 0;
        int row = 1;
        // int dp[100001][100001]{0};
        vector<vector<int>> dp(2, vector<int>(size, 0));

        while (row < size)
        {
            for (int i = 0; i < size - row + 1; i++)
            {
                dp[0][i] = (dp[0][i] + nums[i + row - 1]) % p;
                if (dp[0][i] == target)
                    return row;
                // dp[0][i] = dp[1][i];
                // cout << dp[row][i] << " ";
            }
            // cout << endl;
            row++;
        }
        
        return -1;
    }
};