class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 1)
            if (nums[0] < target)
                return 1;
            else
                return 0;
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (l == r - 1)
                break;
            else if (nums[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (nums[l] >= target)
            return l;
        if (nums[r] >= target)
            return r;
        
        return r + 1;
    }
};