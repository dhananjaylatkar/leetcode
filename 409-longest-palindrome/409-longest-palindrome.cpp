class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        
        int res = 0;
        
        for (auto it: m)
        {
            if (it.second % 2 == 0)
            {
                res += it.second;
                m[it.first] = 0;
            }
            else
            {
                res += it.second - 1;
                m[it.first] = 1;
            }
        }
        for (auto it: m) cout <<  "[" << it.first << "," << it.second << "] "; cout << endl;
        for (auto it: m)
        {
            if (it.second == 1)
            {
                res += it.second;
                break;
            }
        }
        return res;
    }
};