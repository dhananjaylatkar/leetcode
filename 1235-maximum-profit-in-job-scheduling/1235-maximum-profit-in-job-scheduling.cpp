class Solution {
public:
    int dp[50001];
    int helper(vector<vector<int>>& t, int idx, int prevEndTime)
    {
        if (idx == t.size())
        {
            return 0;
        }
        
        if (t[idx][0] < prevEndTime)
        {
            return helper(t, idx+1, prevEndTime);
        }
        
        if (dp[idx] != -1) return dp[idx];
        
        int p1 = helper(t, idx+1, prevEndTime);
        int p2 = 0;
        
        if (t[idx][0] >= prevEndTime)
        {
            p2 = t[idx][2] + helper(t, idx+1, t[idx][1]);
        }
        
        return dp[idx]=max(p1, p2);
        return max(p1, p2);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> t;
        for (int i = 0; i < startTime.size(); i++)
        {
            t.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(t.begin(), t.end());
        return helper(t, 0, 0);
    }
};