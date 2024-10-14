class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        int size = nums.size();
        priority_queue<int> maxHeap;

        for (int i = 0; i < size; i++)
            maxHeap.push(nums[i]);
        
        for (int i = 0; i < k; i++)
        {
            int tmp = maxHeap.top();
            maxHeap.pop();
            ans += tmp;
            // cout << tmp << " " << ans << "\n";
            maxHeap.push(ceil(1.0*tmp/3));
        }

        return ans;
    }
};