class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (string path: paths)
        {
            stringstream ss(path);
            string f;
            ss >> f;
            string dir = f;
            while (ss >> f) {
                size_t found = f.find("(");
                string file = f.substr(0, found);
                string text = f.substr(found, f.length()-found);
                
                if (m.find(text) != m.end())
                {
                    m[text].push_back(dir + "/" +file);
                }
                else
                {
                    m[text] = {dir + "/" + file};
                }
            }
        }
        
        vector<vector<string>> res;
        
        for (auto it: m)
        {
            // cout << it.first << endl;
            if (it.second.size() > 1)
                res.push_back(it.second);
        }
        
        return res;
    }
};