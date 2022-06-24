class Solution {
public:
    int dp[1001][2];
    int helper(vector<int>& nums, int idx, bool visitedFirst)
    {
        int n = nums.size();
        
        if (idx >= n)
        {
            return 0;
        }

        if (dp[idx][visitedFirst] != -1) return dp[idx][visitedFirst];

        int p1 = helper(nums, idx+1, visitedFirst);
        int p2 = 0;
        if (idx == 0)
        {
            p2 += nums[idx] + helper(nums, idx+2, true);
        }
        else if (idx == n-1)
        {
            if (visitedFirst == false)
            {
                p2 += nums[idx] + helper(nums, idx+2, visitedFirst);
            }
        }
        else
        {
            p2 += nums[idx] + helper(nums, idx+2, visitedFirst);
        }
        dp[idx][visitedFirst] = max(p1, p2);
        return dp[idx][visitedFirst];
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, false);
    }
};