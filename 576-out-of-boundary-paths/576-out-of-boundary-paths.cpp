#define MOD 1000000007
class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int dp[51][51][51];
    int helper(int m, int n, int maxMove, int x, int y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n)
        {
            return 1;
        }
        if (maxMove <= 0) return 0;
        
        if (dp[x][y][maxMove] != -1) return dp[x][y][maxMove];
        int path = 0;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dirs[i][0];
            int _y = y + dirs[i][1];
            
            path = (path%MOD + helper(m, n, maxMove-1, _x, _y)%MOD)%MOD;
        }
        return dp[x][y][maxMove] = path;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        
        int res = helper(m, n, maxMove, startRow, startColumn);
        return res;
    }
};