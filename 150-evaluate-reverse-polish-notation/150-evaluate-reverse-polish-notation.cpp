class Solution {
public:
    bool is_operand(string op)
    {
        vector<string> ops = {"+", "-", "*", "/" };
        
        for (auto it: ops)
        {
            if (it==op) return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        
        for (string t: tokens)
        {
            if (is_operand(t))
            {
                long long v2 = s.top();
                s.pop();
                long long v1 = s.top();
                s.pop();
                
                if (t == "+")
                    s.push(v1+v2);
                else if (t == "-")
                    s.push(v1-v2);
                else if (t == "*")
                    s.push(v1*v2);
                else if (t == "/")
                    s.push(v1/v2);
            }
            else {
                s.push(stoi(t));
            }
        }
        return (int)s.top();
    }
};