class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        
        // For k = 1
        int n = s.size();
        string res = s;
        s = s+s;
        
        for (int i = 1; i < n; i++)
        {
            string tmp = s.substr(i, n);
            if (tmp < res)
            {
                res = tmp;
            }
        }
        
        return res;
    }
};