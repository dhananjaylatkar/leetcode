class Solution {
public:
    string minWindow(string s, string t) {
        int n_s = s.length();
        int n_t = t.length();
        
        if (n_s < n_t) return "";
        
        unordered_map<char, int> m_t;
        unordered_map<char, int> m_s;
        for (int i = 0; i < n_t; i++)
        {
            m_t[t[i]]++;
        }
        
        int uniqueCharsInT = m_t.size();
        
        int l = 0; 
        int h = 0;
        
        int currMatchingCharsS = 0;
        
        vector<int> res = {-1, 0}; // len, start
        
        while(h < n_s)
        {
            m_s[s[h]]++;
            
            if (m_t.count(s[h]) && m_t.at(s[h]) == m_s.at(s[h]))
            {
                currMatchingCharsS++;
            }
            
            while (l <= h && uniqueCharsInT == currMatchingCharsS)
            {
                if (res[0] == -1 || res[0] > h-l+1)
                {
                    res[0] = h-l+1;
                    res[1] = l;
                }
                
                m_s[s[l]]--;
                
                if (m_t.count(s[l]) && m_t.at(s[l]) > m_s.at(s[l]))
                {
                    currMatchingCharsS--;
                }
                l++;
            }
            h++;
        }
        
        return res[0] == -1 ? "" : s.substr(res[1], res[0]);
    }
};