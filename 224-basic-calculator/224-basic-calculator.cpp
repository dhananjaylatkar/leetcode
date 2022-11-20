class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int sign = 1;
        int res = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                curr = s[i]-'0';
                while (i+1 < n && isdigit(s[i+1]))
                {
                    curr = (curr*10) + (s[i+1]-'0');
                    i++;
                }
                curr = sign*curr;
                res += curr;
                sign = 1;
            }
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
            else if (s[i] == '(')
            {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                int prev_sign = st.top();
                st.pop();
                
                res = res * prev_sign;
                
                int prev_res = st.top();
                st.pop();
                res = res + prev_res;
            }
        }
        return res;
    }
};