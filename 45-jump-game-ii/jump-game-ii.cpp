class Solution {
public:
    void recursiveJump(vector<int> nums, int& minJump, int pos, int count, int size)
    {
        if (count >= minJump)
            return;
        if (pos >= size - 1)
        {
            minJump = count;
            return;
        }
        for (int i = nums[pos]; i > 0; i--)
        {
            recursiveJump(nums, minJump, pos + i, count + 1, size);
        }
            
    }
    int jump(vector<int>& nums) {
        // int minJump = 1001; 
        // vector<int> dp(size + 1, 1001);
        // vector<int> matrix(size + 1, 0);
        // recursiveJump(nums, minJump, 0, 0, nums.size(), dp, matrix);
        int size = nums.size();
        vector<int> dp(size + 1, 10001);
        dp[size - 1] = 0;
        
        for (int i = size - 2; i >= 0; i--)
        {
            // cout << dp[0] << " " << dp[1] << " " << i << " " << nums[i] << endl;
            for (int j = nums[i]; j > 0; j--)
            {
                if (i + j < size)
                    if (dp[i] > dp[i + j] + 1)
                        dp[i] = dp[i + j] + 1;
            }
        }
            
        return dp[0];


        // return minJump;
    }
};