class Solution {
public:
    bool areSame(vector<int> &a1, vector<int> &a2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a2[i] != 0 && a1[i] < a2[i])
            {
                return false;
            }
        }
        
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        
        vector<int> a2(26,0);
        for (string word: words2)
        {
            vector<int> a_tmp(26,0);
            for (char c: word)
            {
                a_tmp[c-'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                a2[i] = max(a2[i], a_tmp[i]);
            }
        }
        
        for (string word: words1)
        {
            vector<int> a1(26,0);
            for (char c: word)
            {
                a1[c-'a']++;
            }
            if (areSame(a1, a2))
            {
                res.push_back(word);
            }
        }
        
        return res;
    }
};