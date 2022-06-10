class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>& t, int row, int col)
    {
        int m = t.size();
        if (row >= m) return 0;
        int n = t[row].size();
        if (col >= n) return 0;
        
        if (dp[row][col] != -1) return dp[row][col];
        int p1 = t[row][col] + helper(t, row+1, col);
        int p2 = t[row][col] + helper(t, row+1, col+1);
        
        dp[row][col] = min(p1, p2);
        return dp[row][col];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return helper(triangle, 0, 0);
    }
};