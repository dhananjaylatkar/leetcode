class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int start = -1;
        int end = -1;
        while (l <= h)
        {
            int m = (l - h)/2 + h;
            // cout << l << " " << h << " " << m << endl;
            if (nums[m] == target)
            {
                if (m == 0)
                {
                    start = m;
                    break;
                }
                if (nums[m-1] != target) 
                {
                    start = m;
                    break;
                }
                h = m-1;
            }
            else if (nums[m] > target)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        l = 0;
        h = nums.size()-1;
        while (l <= h)
        {
            int m = (l - h)/2 + h;
            // cout << l << " " << h << " " << m << endl;
            if (nums[m] == target)
            {
                if (m == nums.size()-1)
                {
                    end = m;
                    break;
                }
                if (nums[m+1] != target) 
                {
                    end = m;
                    break;
                }
                l = m+1;
            }
            else if (nums[m] > target)
            {
                h = m-1;
            }
            else
            {
                l = m+1;
            }
        }

        return {start, end};
    }
};