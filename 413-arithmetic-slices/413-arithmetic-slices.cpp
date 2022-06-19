class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int curr_len = 1;
        int res = 0;
        int prev_diff = nums[1] - nums[0];
        for (int i = 1; i < n; i++)
        {
            int curr_diff = nums[i] - nums[i-1];
            if (curr_diff == prev_diff)
            {
                curr_len++;
                if (curr_len >= 3)
                {
                    res += curr_len - 2;
                }
            }
            else
            {
                prev_diff = curr_diff;
                curr_len = 2;
            }
        }
        return res;
    }
};