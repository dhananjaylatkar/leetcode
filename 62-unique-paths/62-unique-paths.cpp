class Solution {
public:
    int dp[101][101];
    int helper(int x, int y, int m, int n)
    {
        if (dp[x][y] != -1) return dp[x][y];
        if (x == m-1 && y == n-1)
        {
            return 1;
        }
        
        int p1 = x+1 < m ? helper(x+1, y, m, n): 0;
        int p2 = y+1 < n ? helper(x, y+1, m, n): 0;
        
        dp[x][y] = p1+p2;
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, m, n);
    }
};