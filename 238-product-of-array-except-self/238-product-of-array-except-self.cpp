class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i]*prefix[i-1];
            suffix[n-i-1] = nums[n-i-1]*suffix[n-i];
        }
        
        vector<int> res(n, 0);
        res[0] = suffix[1];
        res[n-1] = prefix[n-2];
        for (int i = 1; i < n-1; i++)
        {
            res[i] = prefix[i-1]*suffix[i+1];
        }
        return res;
    }
};