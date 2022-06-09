class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, int i)
    {
        int n = nums.size();
        
        if (n-1 == i)
        {
            res.push_back(nums);
            return;
        }
        
        for (int j = i; j < n; j++)
        {
            swap(nums[i], nums[j]);
            helper(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
};