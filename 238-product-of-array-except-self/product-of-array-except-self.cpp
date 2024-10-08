class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size, 0), suffix(size, 0);
        prefix[0] = 1;
        suffix[size - 1] = 1;
        for (int i = 1; i < size; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        for (int i = size - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];
        
        vector<int> ans(size, 0);

        for (int i = 0; i < size; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
};