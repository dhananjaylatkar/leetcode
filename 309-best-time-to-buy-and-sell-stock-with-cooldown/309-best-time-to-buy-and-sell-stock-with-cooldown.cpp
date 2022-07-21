class Solution {
public:
    int dp[5001][2];
    int helper (vector<int>& prices, int curr, bool buying)
    {
        if (curr >= prices.size())
        {
            return 0;
        }
        
        if (dp[curr][buying] != -1) return dp[curr][buying];
        
        int p1 = 0;
        int p2 = 0;
        
        if (buying)
        {
            // buy
            p1 = -prices[curr] + helper(prices, curr+1, false);
            // don't buy
            p2 = helper(prices, curr+1, buying);
        }
        else
        {
            // sell
            p1 = prices[curr] + helper(prices, curr+2, true);
            p2 = helper(prices, curr+1, buying);
        }
        
        return dp[curr][buying] = max(p1, p2);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        
        return helper(prices, 0, true);
    }
};