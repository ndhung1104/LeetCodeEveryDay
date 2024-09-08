class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums[0], size = nums.size();
        for (int i = 1; i < size && i <= max; i++)
            if (nums[i] + i > max)
                max = nums[i] + i;
        
        if (max >= size - 1)
            return true;

        return false;
    }
};