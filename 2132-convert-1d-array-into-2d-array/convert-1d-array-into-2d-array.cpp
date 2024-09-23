class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (m * n != original.size())
            return ans;
        
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(original[i * n + j]);
            
            ans.push_back(tmp);
        }
            
        
        return ans;
    }
};