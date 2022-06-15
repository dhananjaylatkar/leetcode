class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int prefix_sum = 0;
        int res = INT_MAX;
        while (r < n)
        {
            prefix_sum += nums[r];
            
            if (prefix_sum >= target)
            {
                while (prefix_sum >= target)
                {
                    res = min(res, r-l+1);
                    prefix_sum -= nums[l++];
                }
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
};