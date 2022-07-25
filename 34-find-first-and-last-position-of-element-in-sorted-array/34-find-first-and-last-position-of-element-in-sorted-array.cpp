class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        vector<int> res(2,-1);
        while (l <= h)
        {
            int mid = l + (h-l)/2;
            if (nums[mid] == target)
            {
                int tmp = mid;
                while (mid-1 >= 0 && nums[mid-1] == target)
                {
                    mid--;
                }
                res[0] = mid;
                
                mid = tmp;
                
                while (mid+1 < nums.size() && nums[mid+1] == target)
                {
                    mid++;
                }
                res[1] = mid;
                return res;
            }
            else if (nums[mid] > target)
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return res;
    }
};