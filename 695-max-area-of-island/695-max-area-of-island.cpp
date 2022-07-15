class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int helper(vector<vector<int>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n)
        {
            return 0;
        }
        
        int area = 1;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dirs[i][0];
            int _y = y + dirs[i][1];
            
            if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;

            if (grid[_x][_y] == 1)
            {
                grid[_x][_y] = 0;
                area += helper(grid, _x, _y);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    res = max(res, helper(grid, i, j));
                }
            }
        }
        
        return res;
    }
};