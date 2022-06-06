class Solution {
public:
    vector<pair<int, int>> twoSum(vector<int>& nums, int start, int sum)
    {
        unordered_map<int, int> m;
        vector<pair<int, int>> res;
        set<pair<int,int>> s;
        for (int i = start; i < nums.size(); i++)
        {
            if (m.find(sum-nums[i]) != m.end())
            {
                if (s.find({sum-nums[i], nums[i]}) == s.end()){
                    res.push_back({m[sum-nums[i]], i});
                    s.insert({sum-nums[i], nums[i]});
                }
            }
            m.insert({nums[i],i});
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            if (nums[i] > 0) break;
            int remainingSum = 0-nums[i];
            vector<pair<int, int>> tmp = twoSum(nums, i+1, remainingSum);
            if (tmp.size())
            {
                for (auto t : tmp)
                res.push_back({nums[i], nums[t.first], nums[t.second]});
            }
        }
        return res;
    }
};