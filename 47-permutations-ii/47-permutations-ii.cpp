class Solution {
public:
    set<vector<int>> res;
    void helper(vector<int>& nums, int idx){
        int len = nums.size();
        if (len-1 == idx){
            res.insert(nums);
            return;
        }
        
        for (int i = idx; i< len; i++){
            swap(nums[idx], nums[i]);
            helper(nums, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        helper(nums, 0);
        vector<vector<int>> tmp(res.begin(), res.end());
        return tmp;
    }
};