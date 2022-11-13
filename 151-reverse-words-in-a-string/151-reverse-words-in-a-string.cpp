class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        int start = 0;
        int i  = 0;
        while (i < n)
        {
            if (s[i] != ' ')
            {
                start = i;
                i++;
                while (i < n && s[i] != ' ')
                {
                    i++;
                }
                st.push(s.substr(start, i-start));
            }
            i++;
        }
        
        string res = "";
        
        while (st.size())
        {
            if (st.size() == 1)
            {
                res += st.top();
            }
            else
            {
                res += st.top() + " ";            
            }
            st.pop();
        }
        
        return res;
    }
};