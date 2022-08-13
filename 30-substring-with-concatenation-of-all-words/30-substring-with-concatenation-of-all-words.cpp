class Solution {
public:
    unordered_map<string, bool> memo;
    bool isValid (unordered_map<string, int> words_map, string sub, int word_len)
    {
        if (memo.find(sub) != memo.end()) return memo[sub];
        for (int j = 0; j < sub.length(); j += word_len)
        {
            string curr = sub.substr(j, word_len);
            if (words_map.find(curr) != words_map.end())
            {
                words_map[curr]--;
                if (words_map[curr] < 0)
                {
                    return memo[sub]=false;
                }
            }
            else
            {
                return memo[sub]=false;
            }
        }
        
        return memo[sub]=true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.length();
        int word_len = words[0].length();
        int all_word_len = word_len * words.size();
        unordered_map<string, int> words_map;
        
        for (string w: words)
        {
            words_map[w]++;
        }
        int i = 0;
        for (int i = 0; i + all_word_len <= n ; i++)
        {
            if (isValid(words_map, s.substr(i, all_word_len), word_len))
            {
                res.push_back(i);
                
            }
        }
        return res;
    }
};