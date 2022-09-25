#define MOD 1000000007
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long int res = 0;
        vector<long long> prefix_sum(n+2, 0);
        vector<long long> d_prefix_sum(n+2, 0);
        
        vector<long long> suffix_sum(n+2, 0);
        vector<long long> d_suffix_sum(n+2, 0);
        
        
        for (int i = 1; i <= n; i++)
        {
            prefix_sum[i] = (prefix_sum[i-1] + strength[i-1])%MOD;
            d_prefix_sum[i] = (d_prefix_sum[i-1] + prefix_sum[i])%MOD;
        }
        
        for (int i = n; i >= 1; i--)
        {
            suffix_sum[i] = (suffix_sum[i+1] + strength[i-1])%MOD;
            d_suffix_sum[i] = (d_suffix_sum[i+1] + suffix_sum[i])%MOD;
        }
        
        
        stack<int> s1, s2;
        vector<int> left(n, -1), right(n, n);
 
        for(int i=0; i < n; i++)
        {
            while(!s1.empty() and strength[s1.top()]>=strength[i])
            {
                right[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() and strength[s2.top()]>strength[i])
            {
                left[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        
        // for (auto it: prefix_sum) cout << it << " "; cout << endl;
        // for (auto it: d_prefix_sum) cout << it << " "; cout << endl;
        // for (auto it: suffix_sum) cout << it << " "; cout << endl;
        // for (auto it: d_suffix_sum) cout << it << " "; cout << endl;
        // for (auto it: left) cout << it << " "; cout << endl;
        // for (auto it: right) cout << it << " "; cout << endl;
        
        for (int i = 0; i < n; i++)
        {
            int curr = strength[i];
            
            // (left[i], i) and (i+1, right[i])
            int l = left[i] + 1;
            int r = right[i] - 1;
            // cout << i << " " << l << " " << r << endl;
            long long r_sum = right_sum(prefix_sum, d_prefix_sum, i+1, r);
            long long l_sum = left_sum(suffix_sum, d_suffix_sum, l, i);
 
            long long curr_sum = (r_sum*(i-l+1))%MOD;
            curr_sum = (curr_sum + (l_sum*(r-i+1))%MOD)%MOD;
 
            long long curr_ans = (curr_sum*curr)%MOD;
 
            res = (res+curr_ans)%MOD;
        }
        
        return res;
    }
    
    long long right_sum(vector<long long int> &prefix_sum, vector<long long int> &d_prefix_sum, int l, int r)
    {
        if (l > r) return 0;
        long long d = r - l + 1;
        long long toSubtract = (d*prefix_sum[l])%MOD;

        long long ans = (d_prefix_sum[r+1] - d_prefix_sum[l] + MOD)%MOD;
        ans = (ans-toSubtract+MOD)%MOD;

        return (int)ans;   
    }
    
    long long left_sum(vector<long long int> &sufix_sum, vector<long long int> &d_sufix_sum, int l, int r)
    {
        if (l > r) return 0;
        long long d = r - l + 1;
        long long toSubtract = (d*sufix_sum[r+2])%MOD;

        long long ans = (d_sufix_sum[l+1] - d_sufix_sum[r+2] + MOD)%MOD;
        ans = (ans-toSubtract+MOD)%MOD;

        return (int)ans;
    }
    
};