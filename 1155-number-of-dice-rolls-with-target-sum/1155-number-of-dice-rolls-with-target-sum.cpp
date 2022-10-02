#define MOD 1000000007
class Solution {
public:
    int dp[31][1001];
    int helper (int n, int k, int target)
    {
        if (target == 0 && n == 0) return 1;
        
        if (n == 0 || target < 0) return 0;
        
        if (dp[n][target] != -1) return dp[n][target];
        
        int p = 0;
        
        for (int i = 1; i <= k; i++)
        {
            p = (p%MOD + helper(n-1, k, target-i)%MOD)%MOD;
        }
        
        return dp[n][target]=p;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k, target);
    }
};