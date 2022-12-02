class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26), f2(26), e1(26), e2(26);
        
        for (char c: word1)
        {
            f1[c-'a']++;
            e1[c-'a'] = 1;
        }
        
        for (char c: word2)
        {
            f2[c-'a']++;
            e2[c-'a'] = 1;
        }
        
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        
        return e1==e2 && f1==f2;
    }
};