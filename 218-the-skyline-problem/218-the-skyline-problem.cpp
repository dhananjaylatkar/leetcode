class Solution {
public:
    vector<vector<int>> transformBuildings (vector<vector<int>>& buildings)
    {
        vector<vector<int>> res;
        
        for (vector<int> b: buildings)
        {
            res.push_back({b[0], -b[2]}); // start
            res.push_back({b[1], b[2]});  // end
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        
        vector<vector<int>> heights = transformBuildings(buildings);
        // for (auto it: heights) cout << it[0] << " " << it[1] << endl;
        map<int, int> pq;
        pq[0] = 1;
        
        for (auto h: heights)
        {
            int curr_height = pq.rbegin()->first;
            if (h[1] < 0) // start
            {
                pq[-h[1]]++;
            }
            else // end
            {
                pq[h[1]]--;
                
                if (pq[h[1]] == 0)
                {
                    pq.erase(pq.find(h[1]));
                }
            }
            int new_height = pq.rbegin()->first;
            if (curr_height != new_height)
            {
                res.push_back({h[0], new_height});
            }
        }
        return res;
    }
};