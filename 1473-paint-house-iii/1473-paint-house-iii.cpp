class Solution {
public:
    int dp[101][101][21]; 
    long long int helper(vector<int>& houses, vector<vector<int>>& cost, int target, int idx, int prevColor)
    {
        if (target < 0) return INT_MAX;
        
        if (idx >= houses.size())
        {
            return target == 0 ? 0 : INT_MAX;
        }
        if (dp[target][idx][prevColor] != -1) return dp[target][idx][prevColor];
        if (houses[idx] != 0)
        {
            if (prevColor == houses[idx])
            {
                
                return dp[target][idx][prevColor] = helper(houses, cost, target, idx+1, houses[idx]);
            }
            return dp[target][idx][prevColor] = helper(houses, cost, target-1, idx+1, houses[idx]);
        }
        
        long long int res = INT_MAX;
        for (int j = 0; j < cost[idx].size(); j++)
        {
            int notSameNeighbour = (prevColor == j+1) ? 0 : 1;
            res = min(res, cost[idx][j] + helper(houses, cost, target - notSameNeighbour, idx+1, j+1));
        }
        
        return dp[target][idx][prevColor] = res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        long long int res = helper(houses, cost, target, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
};