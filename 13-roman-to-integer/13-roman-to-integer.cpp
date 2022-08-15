class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I',1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int i = 0;
        int n = s.length();
        int res = 0;
        while (i < n)
        {
            if (i+1 < n && s[i] == 'I')
            {
                if (s[i+1] == 'V')
                {
                    res += 4;
                    i += 2;
                    continue;
                }
                else if (s[i+1] == 'X')
                {
                    res += 9;
                    i += 2;
                    continue;
                }
            }
            else if (i+1 < n && s[i] == 'X')
            {
                if (s[i+1] == 'L')
                {
                    res += 40;
                    i += 2;
                    continue;
                }
                else if (s[i+1] == 'C')
                {
                    res += 90;
                    i += 2;
                    continue;
                }
            }
            else if (i+1 < n && s[i] == 'C')
            {
                if (s[i+1] == 'D')
                {
                    res += 400;
                    i += 2;
                    continue;
                }
                else if (s[i+1] == 'M')
                {
                    res += 900;
                    i += 2;
                    continue;
                }
            }

            res += m[s[i]];
            i++;
        }
        return res;
    }
};