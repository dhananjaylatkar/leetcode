class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i-1] + nums[i];
            
            nums[i] = max(curr, nums[i]);
            res = max(res, nums[i]);
        }
        
        return res;
    }
};