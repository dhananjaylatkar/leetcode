class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        stack<int> st;
        char prevSign = '+';
        int num = 0;
        
        for (int i = 0; i <= n; i++)
        {
            if (i < n && isdigit(s[i]))
            { 
                num = num*10 + (s[i] - '0');
            }
            else
            {
                // cout << num << endl;
                if (i < n && s[i] == ' ') continue;
                int top = 0;
                switch (prevSign)
                {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        top = st.top();
                        st.pop();
                        st.push(top*num);
                        break;
                    case '/':
                        top = st.top();
                        st.pop();
                        st.push(top/num);
                        break;
                }
                num = 0;
                if (i < n) prevSign = s[i];
            }
        }
        int res = 0;
        
        while(st.size())
        {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};