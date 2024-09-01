class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = nums.size() - 1, start = 0;

        if (pos == -1)
            return 0;

        while (pos > -1 && nums[pos] == val)
            pos--;

        if (pos == -1)
            return 0;
        while (start < pos)
        {
            // cout << start << " " << pos << endl;
            if (nums[start] == val)
            {
                swap(nums[start], nums[pos]);
                pos--;
            }
            else
                start++;
        }
        if (nums[pos] == val)
            return pos;

        return pos + 1;
    }
};