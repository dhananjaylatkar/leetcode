class Solution {
public:
    vector<string> res;
    void helper(string &s, int i)
    {
        int n = s.length();
        
        if (n == i)
        {
            res.push_back(s);
            return;
        }
        if (isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            helper(s, i+1);
            s[i] = toupper(s[i]);
            helper(s, i+1);
        }
        else
        {
            helper(s, i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return res;
    }
};