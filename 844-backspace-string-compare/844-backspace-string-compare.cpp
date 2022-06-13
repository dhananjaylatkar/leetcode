class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = n-1, j = m-1;
        int back_s = 0;
        int back_t = 0;
        while (i > -1 || j > -1)
        {
            while (i > -1)
            {
                if (s[i] == '#')
                {
                    i--;
                    back_s++;
                }
                else if (back_s) // don't include # number of chars
                {
                    i--;
                    back_s--;
                }
                else
                {
                    break;
                }
            }
            
            while (j > -1)
            {
                if (t[j] == '#')
                {
                    j--;
                    back_t++;
                }
                else if (back_t) // don't include # number of chars
                {
                    j--;
                    back_t--;
                }
                else
                {
                    break;
                }
            }
            // cout << i << " " << j << endl;
            if (i > -1 && j > -1 && s[i] != t[j]) return false;
            if ((i > -1 && j < 0) || (i < 0 && j > -1)) return false;
            i--;
            j--;
        }
        
        return true;
    }
};