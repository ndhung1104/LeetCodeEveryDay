class Solution {
public:
    void printMatrix(vector<vector<int>> grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    }
    void DFS(vector<vector<int>>& grid, int m, int n, int row, int col, int pos)
    {
        if (row > -1 && row < m && col > -1 && col < n)
            if (grid[row][col] == 1)
            {
                grid[row][col] = pos;
                DFS(grid, m, n, row - 1, col, pos);
                DFS(grid, m, n, row + 1, col, pos);
                DFS(grid, m, n, row, col - 1, pos);
                DFS(grid, m, n, row, col + 1, pos);
            }
    }
    void findIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int currPos = 2;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    DFS(grid, m, n, i, j, currPos);
                    currPos++;
                }
                       
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        findIsland(grid1);
        findIsland(grid2);
        // printMatrix(grid1);
        // cout << endl;
        // printMatrix(grid2);
        int count = 0;
        int m = grid1.size(), n = grid1[0].size(), size = m * n;
        int* a = new int[m * n]{0};
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid2[i][j])
                    if (a[grid2[i][j]] == -1)
                        continue;
                    else if (a[grid2[i][j]] == 0)
                    {
                        if (grid1[i][j] == 0)
                            a[grid2[i][j]] = -1;
                        else
                            a[grid2[i][j]] = grid1[i][j];
                    }
                    else
                    {
                        if (a[grid2[i][j]] != grid1[i][j])
                            a[grid2[i][j]] = -1;
                    }
                        
        
        for (int i = 0; i < size; i++)
            if (a[i] > 0)
            {
                // cout << i << endl;
                count++;
            }
                
        delete [] a;
        return count;
    }
};