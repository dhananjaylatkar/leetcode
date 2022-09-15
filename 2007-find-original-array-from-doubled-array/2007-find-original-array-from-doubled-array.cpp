class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        
        map<int, int> m;
        
        for (int c: changed)
        {
            m[c]++;
        }
        
        vector<int> res;
        
        for (auto it: m)
        {
            // cout << it.first << " " << it.second << endl;
            if (it.first == 0 && it.second % 2 == 1)
            {
                // If there are odd number of zeroes,
                // double array is not possible.
                break;
            }
            
            if (it.second > 0 && m.find(it.first*2) != m.end())
            {
                // Double is present
                while (m[it.first] && m[it.first*2])
                {
                    res.push_back(it.first);
                    m[it.first]--;
                    m[it.first*2]--;
                }
            }
        }
        
        if (res.size() == n/2) return res;
        
        return {};
    }
};