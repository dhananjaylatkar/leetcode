class Solution {
public:
    int dp[301][11];
    int get_max (vector<int>& jobDifficulty, int start, int end)
    {
        int res = INT_MIN;
        
        for (int i = start; i <= end; i++)
        {
            res = max(res, jobDifficulty[i]);
        }
        
        return res;
    }
    
    int helper (vector<int>& jobDifficulty, int d, int idx)
    {
        int n = jobDifficulty.size();
        
        if (d == 1)
        {
            return get_max(jobDifficulty, idx, n-1);
        }
        
        if (dp[idx][d] != -1) return dp[idx][d];
        
        int res = INT_MAX;
        int difficulty = INT_MIN;
        for (int i = idx; i <= n-d; i++)
        {
            difficulty = max(difficulty, jobDifficulty[i]);
            res = min(res, difficulty+helper(jobDifficulty, d-1, i+1));
        }
        
        return dp[idx][d]=res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        memset(dp, -1, sizeof(dp));
        return helper(jobDifficulty, d, 0);
    }
};