class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //vector<int> ans;

        bool a[300]{0};
        int k = 110;
        int size = nums.size(), count = 0;
        for (int i = 0; i < size; i++)
            if (!a[nums[i] + k])
            {
                //ans.push_back(nums[i]);
                a[nums[i] + k] = true;
                nums[count] = nums[i];
                count++;
            }
        
        return count;
    }
};