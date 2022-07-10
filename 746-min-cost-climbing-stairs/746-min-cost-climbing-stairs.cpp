class Solution {
public:
    int dp[1002];
    int helper(vector<int>& cost, int curr)
    {
        if (curr == cost.size() || curr == cost.size()+1)
        {
            return 0;
        }
        if (curr != -1 && dp[curr] != -1) return dp[curr];
        if (curr == -1 && dp[1001] != -1) return dp[1001];
        int p1 = (curr == -1 ? 0 : cost[curr]) + helper(cost, curr+1);
        int p2 = (curr == -1 ? 0 : cost[curr]) + helper(cost, curr+2);
        // cout << curr << " " << p1 << " " << p2 << endl;
        if (curr == -1)
        {
            return dp[1001] = min(p1, p2);
        }
        return dp[curr]=min(p1, p2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return helper(cost, -1);
    }
};