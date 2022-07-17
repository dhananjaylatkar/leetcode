#define MOD 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int tmp = (dp[i-1][j] + MOD - ((j >= i) ? dp[i-1][j-i] : 0)) % MOD;
                    dp[i][j] = (dp[i][j-1] + tmp) % MOD;
                }
            }
        }

        return (dp[n][k] + (MOD - (k > 0 ? dp[n][k-1]:0))) % MOD;
    }
};