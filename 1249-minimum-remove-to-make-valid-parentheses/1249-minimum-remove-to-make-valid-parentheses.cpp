class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
                res += s[i];
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                    res += s[i];
                }
            }
            else
            {
                res += s[i];
            }
        }

        if (!st.empty())
        {
            n = res.length();
            int i = n-1;

            while (!st.empty() && i >= 0)
            {

                if(res[i] == '(')
                {
                    st.pop();
                    res.erase(i, 1);
                }
                
                i--;
            }
        }
            
        return res;
    }
};