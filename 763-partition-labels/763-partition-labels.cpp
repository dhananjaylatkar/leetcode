class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        
        for (int i = 0; i < n; i++)
        {
            m[s[i]] = i;
        }
        
        int size = 0;
        int end = 0;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            end = max(end, m[s[i]]);
            size++;
            
            if (end == i)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};