class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for (char i : s)
        {
            m[i]++;
        }
        
        for (auto i: m)
        {
            pq.push({i.second, i.first});
        }
        string res = "";
        
        while(pq.size())
        {
            auto top = pq.top();
            while(top.first)
            {
                res.push_back(top.second);
                top.first--;
            }
            pq.pop();
        }
        
        return res;
    }
};