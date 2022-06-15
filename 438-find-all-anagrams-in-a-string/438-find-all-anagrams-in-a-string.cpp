class Solution {
public:
    bool sameArr(vector<int> &window, vector<int> &patt)
    {
        for (int i = 0; i < 26; i++)
        {
            if (window[i] != patt[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if (m > n) return {};

        vector<int> res;
        vector<int> window(26,0);
        vector<int> patt(26,0);
        for (int i = 0; i < m; i++)
        {
            patt[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        if (sameArr(window, patt)) res.push_back(0);
        
        for (int i = 1; i <= n-m; i++)
        {
            window[s[i-1]-'a']--;
            window[s[i+m-1]-'a']++;
            if (sameArr(window, patt)) res.push_back(i);
        }
        return res;
    }
};