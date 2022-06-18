class Solution {
public:
    vector<string> res;
    string paren = "()";
    void helper(int n, int valid, int idx, string &path)
    {
        if (valid == 0 && idx == n)
        {
            res.push_back(path);
            return;
        }
        if (idx > n || valid < 0) return;
        
        path.push_back('(');
        helper(n, valid+1, idx+1, path);
        path.pop_back();
        
        path.push_back(')');
        helper(n, valid-1, idx+1, path);
        path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        helper(n*2, 0, 0, path);
        return res;
    }
};