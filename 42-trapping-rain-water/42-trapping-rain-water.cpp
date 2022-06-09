class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        
        int lmax = height[0];
        int rmax = height[n-1];
        
        int l = 1;
        int r = n-2;
        
        while (l <= r)
        {
            if (lmax <= rmax)
            {
                if (lmax - height[l] > 0) res += lmax - height[l];
                lmax = max(lmax, height[l]);
                l++;
            }
            else
            {
                if (rmax - height[r] > 0) res += rmax - height[r];
                rmax = max(rmax, height[r]);
                r--;
            }
        }
        
        return res;
    }
};