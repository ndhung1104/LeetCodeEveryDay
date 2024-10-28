class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int count[100000 + 1]{0};
        for (int i = 0; i < size; i++)
            count[nums[i]] = 1;
        int longestStreak = -1;
        for (int i = 0; i < size; i++)
            if (count[nums[i]])
            {
                int num = nums[i];
                count[num] = 0;
                if (num <= 316 && count[num * num])
                {
                    int tmpCount = 2;
                    count[num * num] = 0;
                    num = num * num;
                    while (num <= 316 && count[num * num])
                    {
                        tmpCount++;
                        count[num * num] = 0;
                        num = num * num;
                    }
                    if (tmpCount > longestStreak)
                        longestStreak = tmpCount;
                }
                    
                
            }
        
        return longestStreak;
    }
};