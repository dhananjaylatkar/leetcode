class Solution {
public:
    int dp[10001];
    int helper(vector<int>& coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (dp[amount] != -1) return dp[amount];
        int p = 10001;
        for (int i = 0; i < coins.size(); i++)
        {
            int new_amount = amount - coins[i];
            if (new_amount >= 0)
            {
                p = min(p, 1 + helper(coins, new_amount));
            }
        }
        return dp[amount]=p;
            
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = helper(coins, amount);
        return res == 10001 ? -1 : res;
    }
};