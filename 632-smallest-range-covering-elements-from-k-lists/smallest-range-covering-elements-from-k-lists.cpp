class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        int row = nums.size(), max_num = nums[0][0], max_count = 0;

        for (int i = 0; i < row; i++)
        {
            q.push({nums[i][0], i, 0});
            if (nums[i][0] > max_num)
                max_num = nums[i][0];
            max_count += nums[i].size();
        }

        vector<int> ans(2);
        ans[0] = q.top()[0];
        ans[1] = max_num;

        int count = row;

        while (count < max_count)
        {
            vector<int> tmp;
            tmp = q.top();
            q.pop();

            if (tmp[2] == nums[tmp[1]].size() - 1)
                break;

            // cout << tmp[1] << " " << tmp[2] << endl;
            int new_num = nums[tmp[1]][tmp[2] + 1];
            if (new_num > max_num)
                max_num = new_num; // works because the list is non-decreasing
            
            q.push({new_num, tmp[1], tmp[2] + 1});
            int new_min = q.top()[0];

            if ((max_num - new_min < ans[1] - ans[0]) || (max_num - new_min == ans[1] - ans[0] && new_min < ans[0]))
            {
                ans[0] = new_min;
                ans[1] = max_num;
            }
            count++;
        }

        return ans;
    }
};