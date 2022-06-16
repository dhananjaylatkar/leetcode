class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, int idx, vector<int> &path)
    {
        if (idx == nums.size())
        {
            res.push_back(path);
            return;
        }
        
        helper(nums, idx+1, path);
        
        path.push_back(nums[idx]);
        helper(nums, idx+1, path);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path = {};
        helper(nums, 0, path);
        
        return res;
    }
};