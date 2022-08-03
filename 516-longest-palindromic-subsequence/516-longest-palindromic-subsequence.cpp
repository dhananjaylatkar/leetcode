class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i < n-1; i++)
            if (s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        
        
        for (int j = 2; j < n; j++)
        {
            for (int i = 0; i < n && i+j < n; i++)
            {
                if (s[i] == s[i+j])
                {
                    dp[i][i+j] = 2 + dp[i+1][i+j-1];
                }
                else
                {
                    dp[i][i+j] = max(dp[i][i+j-1], dp[i+1][i+j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};