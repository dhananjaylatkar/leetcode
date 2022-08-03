class Solution {
public:
    int dp[1001];
    int helper(int target, vector<int>& nums)
    {
        if (target == 0)
        {
            return 1;
        }
        
        if (dp[target] != -1) return dp[target];
        
        int p = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int new_target = target - nums[i];
            if (new_target >= 0)
            {
                p += helper(new_target, nums); 
            }
        }
        return dp[target]=p;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(target, nums);
    }
};