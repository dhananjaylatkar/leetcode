class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> mat(n, vector(n, 0));
        string maxString;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 1;
            maxString = s.substr(i,1);
            maxLen = 1;
        }
        
        for (int i = 0; i < n-1; i++)
        {
            if(s[i] == s[i+1])
            {
                mat[i][i+1] = 1;
                maxString = s.substr(i,2);
                maxLen = 2;
            }
        }
        
        int i = 0;
        for (int k = 2; k < n; k++)
        {
            int j = i + k;
            while (j < n)
            {
                if (i+1 >= n) continue;
                if (s[i] == s[j] && mat[i+1][j-1] == 1)
                {
                    mat[i][j] = 1;
                    if (maxLen < j-i+1)
                    {
                        maxLen = j-i+1;
                        maxString = s.substr(i, j-i+1);
                    }
                }
                j++;
                i++;
            }
            i = 0;
        }
        return maxString;
    }
};