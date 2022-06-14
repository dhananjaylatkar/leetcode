class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int h = n-1;

        int res = 0;
        
        while(l < h)
        {
            res = max(res, min(height[l], height[h])*(h-l));
            if (height[l] < height[h])
            {
                l++;
            }
            else
            {
                h--;
            }
            
        }
        return res;
    }
};