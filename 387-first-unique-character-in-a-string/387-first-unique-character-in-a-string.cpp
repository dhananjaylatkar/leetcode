class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alpha(26, 0);
        
        for (char c: s)
        {
            alpha[c-'a']++;
        }
        
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (alpha[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};