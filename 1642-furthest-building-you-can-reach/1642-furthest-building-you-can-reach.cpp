class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int hSum = 0;
        priority_queue<int> pq;
        
        int i = 0;
        
        while(i < heights.size()-1)
        {
            if (heights[i] < heights[i+1])
            {
                hSum += heights[i+1] - heights[i];
                pq.push(heights[i+1] - heights[i]);
                while (hSum > bricks && ladders > 0)
                {
                    hSum -= pq.top();
                    ladders--;
                    pq.pop();
                }
                
                if (hSum > bricks && ladders == 0)
                {
                    break;
                }
            }
            i++;
        }
        return i;
    }
};