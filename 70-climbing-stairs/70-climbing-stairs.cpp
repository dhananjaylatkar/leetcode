class Solution {
public:
    //Fibonacci
    int helper(int n)
    {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return helper(n-1)+helper(n-2);
        
    }
    int climbStairs(int n) {
        // return helper(n);
        int dp[46];
        memset(dp, -1, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};