class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<long long> matrix(col, 0);
        long long maxP = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            matrix[j] += points[i][j];
        
        for (int j = 1; j < col; j++)
            matrix[j] = max(matrix[j], matrix[j - 1] - 1);
        
        for (int j = col - 2; j > -1; j--)
            matrix[j] = max(matrix[j], matrix[j + 1] - 1);
    }

    for (int i = 0; i < col; i++)
        maxP = max(maxP, matrix[i]);

    return maxP;
    }
};