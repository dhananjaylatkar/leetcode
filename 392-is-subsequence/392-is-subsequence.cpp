class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_n = s.length();
        int t_n = t.length();
        int s_i = 0;
        int t_i = 0;
        
        while (s_i < s_n && t_i < t_n)
        {
            if (s[s_i] == t[t_i])
            {
                s_i++;
            }
            t_i++;
        }
        return s_i == s_n;
    }
};