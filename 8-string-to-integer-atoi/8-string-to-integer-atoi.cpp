class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long long res = 0;
        int sign = 1;
        
        while (i < n)
        {
            if (isalpha(s[i])) return res;
            if ((s[i] != ' ') && (!isalpha(s[i]) || s[i] == '-' || s[i] == '+'))
            {
                break;
            }
            i++;
        }
        
        if (s[i] == '-') 
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') 
        {
            i++;
        }

        while (i < n && !isalpha(s[i]) && s[i] != ' ' && s[i] != '.' && s[i] != '-' && s[i] != '+')
        {
            long long tmp = 10*res + int(s[i]-'0');

            if (tmp > INT_MAX)
            {
                if (sign == -1) return INT_MIN;
                return INT_MAX;
            }
            res = tmp;
            i++;
        }
        
        return res*sign;
    }
};