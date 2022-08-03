class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_side = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][n-1] == '1')
            {
                max_side = 1;
                dp[i][n-1] = 1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (matrix[m-1][i] == '1')
            {
                max_side = 1;
                dp[m-1][i] = 1;
            }
        }
        
        for (int i = m-2; i >= 0; i--)
        {
            for (int j = n-2; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        return max_side*max_side;
    }
};