class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // int ans = nums.size() - 1;
        // bool searching = true;

        // while (ans > 0)
        // {
        //     for (int i = 0; i < nums.size() - ans; i++)
        //     {
        //         int j = i + ans;
        //         if (nums[i] <= nums[j])
        //             return ans;
        //     }
        //     ans--;
        // }

        // return ans;
        stack<int> monoStack;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (monoStack.empty() || nums[monoStack.top()] > nums[i]) {
                monoStack.push(i);
                // cout << i << " ";
            }
        }
        // cout << endl;
        for (int j = n - 1; j >= 0; --j) {
            while (!monoStack.empty() && nums[j] >= nums[monoStack.top()]) {
                result = max(result, j - monoStack.top());
                monoStack.pop();
            }
        }

        return result;
    }
};