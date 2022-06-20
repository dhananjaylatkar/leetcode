class Solution {
public:
    int dp[13][10001];
    int helper(vector<int>& coins, int amount, int idx)
    {
        if (amount < 0 || idx >= coins.size())
        {
            return INT_MAX-1;
        }
        
        if (amount == 0)
        {
            return 0;
        }
        if (dp[idx][amount] != -1) return dp[idx][amount];
        int p1 = helper(coins, amount, idx+1);
        int p2 = INT_MAX;
        
        for (int i = idx; i < coins.size(); i++)
        {
            if (amount - coins[i] >= 0)
            {
                p2 = min(p2, 1+helper(coins, amount - coins[i], i));
            }
        }
        dp[idx][amount] = min(p1, p2);
        return dp[idx][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = helper(coins, amount, 0);
        return res == INT_MAX-1 ? -1 : res;
    }
};