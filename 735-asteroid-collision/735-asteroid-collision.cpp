class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();
        for (int i = n-1; i >= 0; i--)
        {
            int curr = asteroids[i];
            // cout << curr << endl;
            if (s.size() == 0)
            {
                // cout << "pushing " << curr << endl;
                s.push(curr);
            }
            else
            {
                int top = s.top();
                bool push = false;
                if (top < 0 && curr > 0)
                {
                    while(s.size() && top < 0 && curr > 0)
                    {
                        if (abs(top) < curr)
                        {
                            // cout << "pop " << top << endl;
                            s.pop();
                            push = true;
                            if (!s.size()) break;
                            top = s.top();
                        }
                        else
                        {
                            push = false;
                            break;
                        }
                        
                    }
                    if (s.size() && top < 0 && abs(top) == curr)
                    {
                        // cout << "pop " << top << endl;
                        s.pop();
                        push = false;
                    }
                }
                else
                {
                   push = true; 
                }
                if (push)
                {
                    // cout << "pushing " << curr << endl;
                    s.push(curr);
                }
            }
        }
        
        vector<int> res;
        while (s.size())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};