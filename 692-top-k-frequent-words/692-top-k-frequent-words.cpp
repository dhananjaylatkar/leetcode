class Compare
{
public:
    bool operator() (pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first == b.first) return a.second > b.second;
        
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        for (auto w: words)
        {
            m[w]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        
        for (auto it: m)
        {
            q.push({it.second, it.first});
        }
        
        while (q.size() && k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};