class Solution {
public:
    int dp[101][1001][2];
    int helper(int k, vector<int>& prices, int i, bool buy)
    {
        if (i == prices.size() || k == 0)
        {
            return 0;
        }

        if (dp[k][i][buy] != -1) return dp[k][i][buy];
        
        if (buy)
        {
            // buy
            int p1 = -prices[i] + helper(k, prices, i+1, false);
            // don't buy
            int p2 = helper(k, prices, i+1, true);
            return dp[k][i][buy] = max(p1, p2);
        }
        else
        {
            // sell
            int p3 = prices[i] + helper(k-1, prices, i+1, true);
            // don't sell
            int p4 = helper(k, prices, i+1, false);
            return dp[k][i][buy] = max(p3, p4);
        }
        
        return -1;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        memset(dp, -1, sizeof(dp));
        return helper(k, prices, 0, -1);
    }
};