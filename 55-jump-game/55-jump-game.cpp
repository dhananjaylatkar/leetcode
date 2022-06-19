class Solution {
public:
    bool helper(vector<int>& nums, int idx)
    {
        int n = nums.size();
        if (idx == n) return true;
        
        if (nums[idx] == 0) return false;
        
        for (int i = 1; i <= nums[idx]; i++)
        {
            if (helper(nums, idx+i)) return true;
        }
        
        return false;
        
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        vector<bool> v (n, false);
        v[0] = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == false) return false;
            for (int j = 0; j <= nums[i] && j < n; j++)
            {
                v[i+j] = true;
                if (i+j == n-1) return true;
            }
        }
        return false;
    }
};