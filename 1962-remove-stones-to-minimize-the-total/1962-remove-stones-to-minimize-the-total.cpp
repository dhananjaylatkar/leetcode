class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int p: piles)
        {
            pq.push(p);
        }
        
        while (k)
        {
            int new_val = ceil(pq.top()/2.0);
            pq.pop();
            pq.push(new_val);
            k--;
        }
        int res = 0;
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};