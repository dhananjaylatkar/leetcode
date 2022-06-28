class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        dp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
            }
            else
            {
                int pos = lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
                dp[pos] = nums[i];
            }
        }
        return dp.size();
    }
};