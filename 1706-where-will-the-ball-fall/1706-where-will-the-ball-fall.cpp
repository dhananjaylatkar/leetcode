class Solution {
public:
    int m;
    int n;
    int dp[102][102];
    bool isValid(int x, int y)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int helper(vector<vector<int>>& grid, int x, int y)
    {
        // cout << x << " " << y << " " << m << " " << n << endl;
        if (x == m) return y;
        
        if (isValid(x, y))
        {
            if (grid[x][y] == 1 && isValid(x, y+1) && grid[x][y+1] == 1)
            {
                if (dp[x+1][y+1] != -2) return dp[x+1][y+1];
                else
                {
                    dp[x+1][y+1] = helper(grid, x+1, y+1);
                    return dp[x+1][y+1];
                }
            }
            
            if (grid[x][y] == -1 && isValid(x, y-1) && grid[x][y-1] == -1)
            {
                if (dp[x+1][y-1] != -2) return dp[x+1][y-1];
                else
                {
                    dp[x+1][y-1] = helper(grid, x+1, y-1);
                    return dp[x+1][y-1];
                }
            }
            
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < 102; i++)
        {
            for (int j = 0; j < 102; j++)
            {
                dp[i][j] = -2;
            }
        }
        vector<int> res;
        
        for (int i = 0; i < n; i++)
        {
            res.push_back(helper(grid, 0, i));
        }
        return res;
    }
};