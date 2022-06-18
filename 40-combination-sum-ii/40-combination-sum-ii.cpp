class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, int idx, vector<int> &path)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        
        if (target < 0 || idx >= candidates.size()) return;
        
        for (int i = idx; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0) break;
            if (i > idx && candidates[i] == candidates[i-1])
            {
                continue;
            }

            path.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path = {};
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, path);
        return res;
    }
};