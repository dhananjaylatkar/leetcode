class Solution {
public:
    set<vector<int>> res;
    void helper(vector<int> &nums, int idx, vector<int> &curr)
    {
        int curr_size = curr.size();

        if (curr_size > 1) res.insert(curr);
        
        int last = -101;
        if (curr_size != 0) last = curr[curr_size-1];

        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] >= last)
            {
                curr.push_back(nums[i]);
                helper(nums, i+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        helper(nums, 0, tmp);
        
        vector<vector<int>> ret(res.begin(), res.end());
        return ret;
    }
};