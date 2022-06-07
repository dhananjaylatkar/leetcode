class Solution {
public:
    string create_unique_string(string &s)
    {
        // cout << s1 << " " << s2 << endl;
        vector<int> a_s(26, 0);
        
        for (int i = 0; i < s.length(); i++)
        {
            a_s[s[i]-'a']++;
        }
        
        string res = "";
        for (int i = 0; i < 26; i++)
        {
            if (a_s[i])
            {
                res += to_string(i+'a') + "-" + to_string(a_s[i]);

            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string key = create_unique_string(strs[i]);
            // cout << strs[i] << " " << key << endl;
            if (map.find(key) != map.end())
            {
                map[key].push_back(strs[i]);
            }
            else
            {
                map[key] = {strs[i]};
            }
        }
        for (auto it: map)
        {
            res.push_back(it.second);
        }
        return res;
    }
};