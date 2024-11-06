class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int maxNums = nums[0], prevMaxNums = 0, curSetBit = __builtin_popcount(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            int tmpSetBit =__builtin_popcount(nums[i]); 
            // cout << maxNums << " " << prevMaxNums << " " << curSetBit << " " << tmpSetBit << endl;
            if (tmpSetBit != curSetBit)
            {
                prevMaxNums = maxNums;
                maxNums = nums[i];
                curSetBit = tmpSetBit;
            }
            if (nums[i] > maxNums)
                maxNums = nums[i];
            
            if (nums[i] < prevMaxNums)
                return false;
        }

        return true;
    }
};