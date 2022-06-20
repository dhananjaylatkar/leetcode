class Solution {
public:
    int originalNum;
    int dp[59];
    int helper(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (dp[n] != -1) return dp[n];
        // if n is original number, we don't want to consider itself in max()
        dp[n] = 0;
        if (n != originalNum) dp[n] = n;
        
        for (int i = 1; i < n; i++)
        {
            dp[n] = max(dp[n], helper(i)*helper(n-i));
        }
        return dp[n];
    }
    int integerBreak(int n) {
        originalNum = n;
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};