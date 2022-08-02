class Solution {
public:
    int dp[101][101];
    int helper(vector<vector<int>>& matrix, int row, int idx)
    {
        int n = matrix.size();
        
        if (row == n)
        {
            return 0;
        }
        
        if (dp[row][idx] != -1) return dp[row][idx];
        
        int p1 = INT_MAX;
        int p2 = INT_MAX;
        int p3 = INT_MAX;

        if (idx-1 >= 0)
        {
            p1 = matrix[row][idx] + helper(matrix, row+1, idx-1);
        }
        if (idx+1 < n)
        {
            p2 = matrix[row][idx] + helper(matrix, row+1, idx+1);
        }
        p3 = matrix[row][idx] + helper(matrix, row+1, idx);
        
        return dp[row][idx] = min(p1, min(p2, p3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            res = min(res, helper(matrix, 0, i));
        }
        return res;
    }
};