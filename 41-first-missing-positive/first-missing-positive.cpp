class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            // cout << i << endl;
            if (nums[i] < 1)
                nums[i] = i + 1;
            else if(nums[i] > i + 1)
            {
                if (nums[i] < nums.size() + 1)
                {
                    if (nums[nums[i] - 1] == nums[i])
                    {
                        // int tmp = nums[i];
                        // if (nums[i] - 1 == i + 1)
                        //     nums[i] = -1;
                        // else
                        //     nums[i] = i + 1;
                        // nums[nums[i] - 1] = nums.size() + 3;
                        nums[i] = -1;
                        i--;
                    }
                    else
                    {
                        swap(nums[i], nums[nums[i] - 1]);
                        i--;
                    }
                }
                else
                    nums[i] = i + 1;
            }
            else
            {
                if (nums[i] > 0 && nums[nums[i] - 1])
                {
                    int tmp = nums[i];
                    if (nums[i] - 1 == i + 1)
                        nums[i] = -1;
                    else
                        nums[i] = i + 1;
                    nums[tmp - 1] = -1;
                    // nums[i] = -1;
                    
                }
                // nums[nums[i] - 1] = -1;
                // nums[i] = i + 1;
            }
            // for (int i = 0; i < nums.size(); i++)
            //     cout << nums[i] << " ";
            // cout << endl;
        }
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                return nums[i];
        
        return nums.size() + 1;
    }
};