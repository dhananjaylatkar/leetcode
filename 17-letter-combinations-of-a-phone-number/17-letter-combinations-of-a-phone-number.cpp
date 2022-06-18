class Solution {
public:
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> res;
    
    void helper(string digits, int idx, string &path)
    {
        if (idx == digits.length())
        {
            res.push_back(path);
            return;
        }
        int d = digits[idx] - '0';
        for (int i = 0; i < letters[d].length(); i++)
        {
            path.push_back(letters[d][i]);
            helper(digits, idx+1, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        string path = "";
        helper(digits, 0, path);
        return res;
    }
};