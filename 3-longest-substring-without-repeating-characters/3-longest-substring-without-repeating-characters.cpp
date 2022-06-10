class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpha(256, 0);
        int n = s.length();
        int res = 0;
        int p1 = 0;
        int p2 = 0;
        while (p1 < n && p2 < n)
        {
            // cout << p1 << " " << p2 << endl;
            // cout << s[p1] << " " << s[p2] << endl;
            
            if (alpha[s[p2]] == 0)
            {
                
                alpha[s[p2]] = 1;
                p2++;
            }
            else
            {
                while(s[p1] != s[p2]){
                    alpha[s[p1]] = 0;
                    p1++;
                }
                alpha[s[p1]] = 0;
                p1++;
                // p2++;
            }
            res = max(res, p2-p1);
        }
        // cout << p1 << " " << p2 << endl;
        
        return res;
    }
};