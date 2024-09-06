class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int> ans;
        vector<int> count(30000, 0);
        int size = nums.size(), copy = 0, check = 0;

        while (check < size)
        {
            if (count[nums[check] + 10000] < 2)
            {
                count[nums[check] + 10000]++;
                nums[copy] = nums[check];
                check++;
                copy++;
            }
            else
            {
                check++;
            }
        }

        return copy;
    }
};