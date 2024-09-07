class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int kM[100001]{0}, numsSize = nums.size(), totalR = k;
        while (totalR > 0)
        {
            if (totalR >= numsSize)
                k = numsSize;
            else
                k = totalR;

            totalR -= k;
            
            for (int i = 0; i < k; i++)
                kM[i] = nums[numsSize - 1 - i];

            for (int i = numsSize - 1; i >= k; i--)
                nums[i] = nums[i - k];

            for (int i = 1; i <= k; i++)
                nums[k - i] = kM[i - 1];
        }
        
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {

//         while (k > 0)
//         {
//             int tmp = nums[nums.size() - 1];
//             nums.pop_back();
//             nums.insert(nums.begin(), tmp);
//             k--;
//         }
//     }
// };