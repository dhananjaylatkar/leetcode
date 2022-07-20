class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - prices[i-1];
            if (profit > 0)
            {
                res += profit;
            }
        }
        
        return res;
    }
};