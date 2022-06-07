class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_set<string> set;
        unordered_set<string> res;
        for (int i = 0; i < s.length() - 9; i++)
        {
            string subSeq = s.substr(i, 10);
            
            if (set.find(subSeq) != set.end())
            {
                res.insert(subSeq);
            }
            else
            {
                set.insert(subSeq);
            }
        }
        return vector(res.begin(), res.end());
    }
};