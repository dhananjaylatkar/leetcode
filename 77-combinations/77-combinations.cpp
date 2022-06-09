class Solution {
public:
    vector<vector<int>> res;
    void helper(int n, int k, vector<int> &range, int curr)
    {
        if (k == 0)
        {
            res.push_back(range);
            return;
        }
        
        for(int i = curr; i <= n; i++)
        {
            range.push_back(i);
            helper(n, k-1, range, i+1);
            range.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> range;
        
        helper(n, k, range, 1);
        
        return res;
    }
};