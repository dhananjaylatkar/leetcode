class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        deque<string> s;
        
        int i = 1;
        
        while (i < n)
        {
            int end = path.find('/', i);
            if (end == string::npos) end = n;
            
            string tmp = path.substr(i, end-i);
            i = end+1;
            
            if (tmp == "" || tmp == ".")
            {
                continue;
            }
            else if (tmp == "..")
            {
                if (!s.empty())
                {
                    s.pop_front();
                }
            }
            else
            {
                s.push_front(tmp);
            }
        }
        string res = "";
        while (!s.empty())
        {
            res += "/" + s.back();
            s.pop_back();
        }
        return res == "" ? "/" : res;
    }
};