class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void helper(vector<vector<char>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >=n) return;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dirs[i][0];
            int new_y = y + dirs[i][1];
            if (!(new_x < 0 || new_x >= m || new_y < 0 || new_y >=n))
            {
                if (grid[new_x][new_y] == '1')
                {
                    helper(grid, new_x, new_y);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    helper(grid, i, j);
                }
            }
        }
        return res;
    }
};