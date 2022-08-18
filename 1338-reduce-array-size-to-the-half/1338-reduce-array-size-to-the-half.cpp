class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num: arr)
        {
            freq[num]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for (auto f: freq)
        {
            pq.push({f.second, f.first});
        }
        
        int removed = 0;
        int n = arr.size();
        int res = 0;
        while (removed < n/2)
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            removed += curr.first;
            res++;
        }
        
        return res;
    }
};