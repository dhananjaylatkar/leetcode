class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
        int i = 0;
        int len = strs[0].length();
        while (i < len)
        {
            char curr = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != curr) return res;
            }
            res += strs[0][i++];
        }
        return res;
    }
};