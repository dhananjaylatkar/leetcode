class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        int l = 0;
        int h = n-1;
        while(l < h)
        {
            if (s[l] != s[h]) return 2;
            l++;
            h--;
        }
        
        return 1;
    }
};