class Solution {
public:
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bank_set(bank.begin(), bank.end());;
        // bank_set.insert(start);
        // bank_set.insert(end);
        
        queue<string> q;
        unordered_set<string> visited;
        
        int res = 0;
        
        q.push(start);
        visited.insert(start);
        
        while (!q.empty())
        {
            int n = q.size();
            
            while (n--)
            {
                string curr = q.front();
                q.pop();
                
                if (curr == end) return res;
                
                for (char c: "ACGT")
                {
                    for (int i = 0; i < 8; i++)
                    {
                        string next = curr;
                        next[i] = c;
                        
                        if (!visited.count(next)
                           && bank_set.count(next))
                        {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};