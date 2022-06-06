class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        vector<int> tmp_arr;
        
        tmp_arr.push_back(nums[0]);
        
        for (int i = 0; i < n; i++)
        {
            if (tmp_arr.back() < nums[i])
            {
                tmp_arr.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(tmp_arr.begin(), tmp_arr.end(), nums[i]) - tmp_arr.begin();
                tmp_arr[idx] = nums[i];
            }
        }
        return tmp_arr.size() > 2;
    }
};