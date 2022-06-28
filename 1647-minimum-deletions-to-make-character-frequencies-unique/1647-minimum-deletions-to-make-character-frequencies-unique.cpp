class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        
        unordered_set<int> set;
        int res = 0;
        for (auto it: m)
        {
            int count = it.second;
            
            while (count > 0 && set.count(count) != 0)
            {
                res++;
                count--;
            }
            if (count)
            {
                set.insert(count);
            }
        }
        return res;
    }
};