class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int> m;
        
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }
        
        int res = 0;
        bool isOddPalidromeTaken = false;
        for (auto it: m)
        {
            string curr = it.first;
            int curr_count = it.second;
            
            string rev_curr = "";
            rev_curr.push_back(curr[1]);
            rev_curr.push_back(curr[0]);
            
            if (curr[0] == curr[1])
            {
                if (curr_count % 2 != 0)
                {
                    if (!isOddPalidromeTaken)
                    {
                        res += curr_count*2;
                        isOddPalidromeTaken = true;
                    }
                    else
                    {
                        res += (curr_count-1)*2;
                    }
                }
                else
                {
                    res += (curr_count)*2;
                }
            }
            else if (curr_count && m.find(rev_curr) != m.end())
            {
                int rev_count = m[rev_curr];
                m[rev_curr] = 0;
                res += 4 * min(rev_count, curr_count);
            }
            // cout << curr << " " << rev_curr << " " << res << endl;
        }
        
        return res;
    }
};