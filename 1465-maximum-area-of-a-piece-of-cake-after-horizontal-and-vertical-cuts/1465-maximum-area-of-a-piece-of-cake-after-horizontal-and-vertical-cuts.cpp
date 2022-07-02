class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxH = horizontalCuts[0];
        int maxV = verticalCuts[0];
        
        horizontalCuts.push_back(h);
        // for (auto i: horizontalCuts) cout << i << " "; cout << endl;
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }

        verticalCuts.push_back(w);
        // for (auto i: verticalCuts) cout << i << " "; cout << endl;
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxV = max(maxV, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return (1LL*maxH*maxV)%1000000007;
    }
};