class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> res;
        int n = s.length();
        vector<int> cummulative(n, 0);
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (i > 0)
                    cummulative[i] += cummulative[i-1]+1;
                else
                    cummulative[i] = 1;
            }
            else
            {
                if (i > 0)
                    cummulative[i] = cummulative[i-1];
            }

            if (s[i] == '|')
            {
                left[i] = i;
            }
            else
            {
                if (i > 0)
                    left[i] = left[i-1];
            }
            if (s[n-i-1] == '|')
            {
                right[n-i-1] = n-i-1;
            }
            else
            {
                if (n-i < n)
                    right[n-i-1] = right[n-i];
            }
        }
        // for (int it: cummulative)
        //     cout << it << " ";
        // cout << endl;
        // for (int it: left)
        //     cout << it << " ";
        // cout << endl;
        // for (int it: right)
        //     cout << it << " ";
        // cout << endl;
        
        for (vector<int> q: queries)
        {   
            int l = left[q[1]];
            int r = right[q[0]];
            if (l != -1 && r != -1 && l > r)
            {
                res.push_back(cummulative[l]-cummulative[r]);
            }
            else
            {
                res.push_back(0);
            }
        }
        return res;
    }
};