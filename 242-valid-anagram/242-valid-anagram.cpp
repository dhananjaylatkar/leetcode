class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (n != m) return false;
        
        vector<int> a(26,0);
        
        for (int i = 0; i < n; i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 0) return false;
        }
        
        return true;
    }
};