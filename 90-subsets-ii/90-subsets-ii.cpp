class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int> &path, set<vector<int>> &res)
    {
        if (idx == nums.size())
        {
            res.insert(path);
            return;
        }
        
        helper(nums, idx+1, path, res);
        
        path.push_back(nums[idx]);
        helper(nums, idx+1, path, res);
        path.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path = {};
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, res);
        
        return vector<vector<int>> (res.begin(), res.end());
    }
};