class Solution {
public:
    string makeGood(string s) {
        vector<char> st;
        
        for (char c: s)
        {
            if (!st.empty() && abs(st.back()-c) == 32)
            {
                st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }
        
        string res(st.begin(), st.end());
        
        return res;
    }
};