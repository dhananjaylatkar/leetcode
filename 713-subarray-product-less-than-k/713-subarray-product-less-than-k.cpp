class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0;
        int prefix_mul = 1;
        int n = nums.size();
        int l = 0, r = 0;
        
        while (r < n)
        {
            prefix_mul *= nums[r];
            while (prefix_mul >= k)
            {
                prefix_mul /= nums[l];
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
};