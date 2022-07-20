class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, queue<string>> map;
        vector<int> alpha(26, 0);
        
        for (int i = 0; i < s.length(); i++)
        {
            alpha[s[i]-'a']++;
        }
        
        for (int i = 0; i < words.size(); i++)
        {
            string curr = words[i];
            if (alpha[curr[0]-'a'])
            {
                map[curr[0]].push(curr);
            }
        }
        
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            int len = map[c].size();
            
            for (int j = 0; j < len; j++)
            {
                string curr = map[c].front();
                map[c].pop();

                string _curr = curr.substr(1);
                if (_curr.length() == 0)
                {
                    res++;
                }
                else
                {
                    if (alpha[_curr[0]-'a'])
                    map[_curr[0]].push(_curr);
                }
            }
        }
        return res;
    }
};