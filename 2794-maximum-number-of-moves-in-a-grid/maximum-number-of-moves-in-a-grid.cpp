class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> tmp(grid.size(), vector<int>(grid[0].size(), 0));
        int colSize = grid[0].size(), rowSize = grid.size();
        for (int i = 0; i < rowSize; i++)
            tmp[i][colSize - 1] = 1;
        for (int col = grid[0].size() - 2; col >= 0; col--)
            for (int row = 0; row < grid.size(); row++)
            {
                int tmp1 = 0, tmp2 = 0, tmp3 = 0;
                if (row - 1 > -1 && grid[row][col] < grid[row - 1][col + 1])
                    tmp1 = tmp[row - 1][col + 1];
                if (grid[row][col] < grid[row][col + 1])
                    tmp2 = tmp[row][col + 1];
                if (row + 1 < grid.size() && grid[row][col] < grid[row + 1][col + 1])
                    tmp3 = tmp[row + 1][col + 1];
                tmp[row][col] = 1 + max(max(tmp1, tmp2), tmp3);
            }
        // for (int i = 0; i < rowSize; i++)
        // {
        //     for (int j = 0; j < colSize; j++)
        //         cout << tmp[i][j] << " ";
        //     cout << endl;
        // }
            
        int maxMove = 0;
        for (int i = 0; i < rowSize; i++)
            maxMove = max(maxMove, tmp[i][0]);
        
        return maxMove - 1;
    }
};