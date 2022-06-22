class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;
        for (int i : nums)
        {
            m[i]++;
        }
        
        for (auto i: m)
        {
            pq.push({i.second, i.first});
        }
        vector<int> res;
        
        while(k)
        {
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};