class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++)
        {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
            
            if (m[nums[i]] > size / 2)
                return nums[i];
        }

        return -1;
    }
};