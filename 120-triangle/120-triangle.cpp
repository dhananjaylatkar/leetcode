class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>& t, int row, int idx)
    {
        int n = t.size();
        if (row == n)
        {
            return 0;
        }
        
        if (dp[row][idx] != -1) return dp[row][idx];
        
        int p1 = INT_MAX;
        int p2 = INT_MAX;

        if (idx < t[row].size())
        {
            p1 = t[row][idx] + helper(t, row+1, idx+1);
            p2 = t[row][idx] + helper(t, row+1, idx);
        }
        return dp[row][idx]=min(p1, p2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return helper(triangle, 0, 0);
    }
};