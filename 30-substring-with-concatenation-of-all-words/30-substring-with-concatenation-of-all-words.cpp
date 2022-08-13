class Solution {
public:
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
        
        for (int i = 0; i < n; i++)
        {
            unordered_map<string, int> found_words_map;
            
            for (int j = i; j < n && j < i+all_word_len; j += word_len)
            {
                string curr = s.substr(j, word_len);
                
                if (words_map.find(curr) != words_map.end())
                {
                    found_words_map[curr] ++;
                    if (found_words_map[curr] > words_map[curr])
                    {
                        // too many words found
                        break;
                    }
                    
                }
                else
                {
                    // unknown word detected
                    break;
                }
            }
            if (found_words_map == words_map)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};