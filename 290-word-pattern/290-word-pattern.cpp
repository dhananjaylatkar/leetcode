class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        
        int i = 0, j = 0;
        int n = p.length();
        int m = s.length();

        while (i < n)
        {
            string tmp = "";
            while(j < m && s[j] != ' ')
            {
                tmp+=s[j];
                j++;
                
            }
            if (tmp == "") return false;
            // cout << p[i] << " " << tmp << endl;
            
            if (map.find(p[i]) != map.end())
            {
                if (map[p[i]] != tmp) return false;
            }
            else
            {
                // cout << "Adding " << p[i] << " " << tmp << endl;
                if (set.find(tmp) != set.end()) return false;
                map[p[i]] = tmp;
                set.insert(tmp);
            }
            
            i++; j++;
        }
        if (j < m) return false;
        return true;
    }
};