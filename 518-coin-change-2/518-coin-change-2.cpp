class Solution {
public:
    int dp[5001][301];
    int helper(int amount, vector<int>& coins, int idx)
    {
        if (amount == 0)
        {
            return 1;
        }
        
        if (dp[amount][idx] != -1) return dp[amount][idx];
        
        int p = 0;
        
        for (int i = idx; i < coins.size(); i++)
        {
            int new_amount = amount - coins[i];
            if (new_amount >= 0)
            {
                p += helper(new_amount, coins, i); 
            }
        }
        return dp[amount][idx]=p;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(amount, coins, 0);
    }
};