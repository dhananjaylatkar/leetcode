class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> v;
        v.push_back(nums[0]);
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= v.back())
            {
                v.push_back(nums[i]);
            }
            else
            {
                int pos = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[pos] = nums[i];
            }
        }
        // for (auto i: v) cout << i << " "; cout << endl;
        return v.size() == n-1 || v.size() == n;
    }
};