class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int l = 0;
        int h = n-1;
        
        if (nums[l] < nums[h]) return nums[l];
        
        while (l <= h)
        {
            int m = (l-h)/2 + h;
            // cout << l << " " << m << " " << h << endl;
            if (m < n-1 && nums[m] > nums[m+1]) return nums[m+1];
            if (m > 0 && nums[m] < nums[m-1]) return nums[m];
            
            if (nums[m] > nums[l])
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }
        return -1;
    }
};