class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // if (n == 1) return 0;
        vector<int> v (n, 0);
        // v[0] = 1;
        for (int i = 0; i < n; i++)
        {
            // for (auto k: v) cout << k << " "; cout << endl;
            for (int j = 1; j <= nums[i] && i+j < n; j++)
            {
                // cout << i << " " << i+j << " | " << v[j] << " " << v[i+j] << endl;
                if (v[i+j] == 0)
                {
                    // cout << "found 0\n";
                    v[i+j] = 1+v[i];
                }
                else
                {
                    v[i+j] = min(v[i+j], 1+v[i]);
                }
                
                if (i+j == n-1) break;
            }
            // for (auto k: v) cout << k << " "; cout << endl;
            // cout << "==========\n" ;
        }
        
        return v[n-1];
    }
};