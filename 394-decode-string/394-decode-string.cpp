class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int n = s.length();
        int i = 1;
        stack<char> st;
        st.push(s[0]);
        while (i < n)
        {
            if (s[i] != ']')
            {
                // cout << "push " << s[i] << endl;
                st.push(s[i]);
            }
            else
            {
                // cout << "found closing bracket at " << i << endl;
                string tmp = "";
                while(st.top() != '[')
                {
                    tmp += st.top();
                    st.pop();
                }
                st.pop(); // pop '['
                // cout << "tmp " << tmp << endl;
                int num = 0;
                int d = 1;
                while(!st.empty() && isdigit(st.top()))
                {
                    num += (st.top() - '0') * d;
                    d = 10*d;
                    st.pop();
                }
                
                // cout << "num " << num << endl;
                int tmp_len = tmp.size();
                while (num--)
                {
                    int j = tmp_len -1;
                    while(j >= 0)
                    {
                        st.push(tmp[j]);
                        j--;
                    }
                }
            }
            i++;
        }
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};