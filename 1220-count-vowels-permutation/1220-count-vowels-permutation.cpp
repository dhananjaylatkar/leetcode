#define MOD 1000000007

class Solution {
public:
    string vov = "aeiou";
    unordered_map<char, int> m = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    int dp[20001][5];
    int helper(int n, char curr)
    {
        if (n == 0)
        {
            return 1;
        }
        
        if (curr != '\0' && dp[n][m[curr]] != -1)
        {
            return dp[n][m[curr]];
        }
        
        int p = 0;
        
        if (curr == '\0')
        {
            for (char c: vov)
            {
                p = (p%MOD + helper(n-1, c)%MOD)%MOD;
            }
        }
        else
        {
            switch (curr)
            {
                case 'a':
                    p = (p%MOD + helper(n-1, 'e')%MOD)%MOD;
                    break;
                case 'e':
                    p = (p%MOD + helper(n-1, 'a')%MOD)%MOD;
                    p = (p%MOD + helper(n-1, 'i')%MOD)%MOD;
                    break;
                case 'i':
                    for (char c: vov)
                    {
                        if (c != 'i')
                        {
                            p = (p%MOD + helper(n-1, c)%MOD)%MOD;
                        }
                    }
                    break;
                case 'o':
                    p = (p%MOD + helper(n-1, 'i')%MOD)%MOD;
                    p = (p%MOD + helper(n-1, 'u')%MOD)%MOD;
                    break;
                case 'u':
                    p = (p%MOD + helper(n-1, 'a')%MOD)%MOD;
                    break;
            }
        }
        return dp[n][m[curr]] = p%MOD;
    }
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, '\0');
    }
};