class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till_now = prices[0];
        int res = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            res = max(res, prices[i] - min_till_now);
            
            min_till_now = min(min_till_now, prices[i]);
        }
        
        return res;
    }
};