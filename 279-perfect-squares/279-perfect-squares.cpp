class Solution {
public:
    int dp[10001];
    int helper(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1) return dp[n];
        
        int p = INT_MAX;
        
        for (int i = 1; ; i++)
        {
            int new_n = n - i*i;
            if (new_n >= 0)
            {
                p = min(p, 1 + helper(new_n));
            }
            else
            {
                break;
            }
        }
        return dp[n]=p;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};