class Solution {
public:
    int dp[101][2];
    int helper(vector<int>& nums, int idx, bool robbed_first)
    {
        int n = nums.size();
        
        if (idx >= n) return 0;
        
        if (dp[idx][robbed_first] != -1) return dp[idx][robbed_first];
        
        if (idx == n-1 && robbed_first) return 0;
        int p1 = 0, p2 = 0;
        if (idx == 0)
        {
            p1 = nums[idx] + helper(nums, idx+2, true);
            p2 = helper(nums, idx+1, false);
        }
        else 
        {
            p1 = nums[idx] + helper(nums, idx+2, robbed_first);
            p2 = helper(nums, idx+1, robbed_first);
        }
        
        return dp[idx][robbed_first] = max(p1, p2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, false);
    }
};