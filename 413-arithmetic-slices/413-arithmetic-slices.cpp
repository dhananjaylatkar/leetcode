class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int res = 0;
        int max_len = 2;
        int diff = nums[1] - nums[0];
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i-1] == diff)
            {
                max_len++;
            }
            else
            {
                res += (max_len-2)*(max_len-1)/2;
                max_len = 2;
                diff = nums[i] - nums[i-1];
            }
        }
        res += (max_len-2)*(max_len-1)/2;
        return res;
    }
};