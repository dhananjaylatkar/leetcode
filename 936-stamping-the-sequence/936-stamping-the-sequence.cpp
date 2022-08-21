class Solution {
public:
    bool canReplace(string &stamp, string &target, int start)
    {
        for (int i = start; i < stamp.length()+start; i++)
        {
            if (target[i] != '?' && target[i] != stamp[i-start])
            {
                return false;
            }
        }
        return true;
    }
    
    int replace(string &target, int start, int len)
    {
        int count = 0;
        
        for (int i = start; i < start+len; i++)
        {
            if (target[i] != '?')
            {
                target[i] = '?';
                count++;
            }
        }
        return count;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int count = 0;
        vector<bool> visited(target.length(), 0);
        vector<int> res;
        
        while (count != target.length())
        {
            bool didchange = false;
            for (int i = 0; i <= target.length() - stamp.length(); i++)
            {
                if (!visited[i] && canReplace(stamp, target, i))
                {
                    visited[i] = 1;
                    didchange = true;
                    res.push_back(i);
                    count += replace(target, i, stamp.length());
                    
                    if (count == target.length())
                    {
                        break;
                    }
                }
            }
            if (!didchange)
            {
                return {};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};