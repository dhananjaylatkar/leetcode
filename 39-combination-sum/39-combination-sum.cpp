class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, vector<int> &path)
    {
        if (target < 0) return;
        
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0 && (!path.size() || path.back() <= candidates[i]))
            {
                path.push_back(candidates[i]);
                helper(candidates, target-candidates[i], path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path = {};
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, path);
        return res;
    }
};