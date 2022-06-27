class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        
        // Put all char count in max heap
        unordered_map<char, int> m;
        for (char t: tasks)
        {
            m[t]++;
        }
        
        priority_queue<int> pq;
        for (auto task: m)
        {
            pq.push(task.second);
        }
        
        // use queue to keep track of cool down time 
        // <count, time_when_cool_down_will_be_complete>
        queue<pair<int, int>> coolDown;
        
        int res = 0;
        
        while (pq.size() || coolDown.size())
        {
            res++;
            if (pq.size())
            {
                int top = pq.top();
                pq.pop();
                // if max element in heap is non zero then push it queue
                if (top-1) coolDown.push({top-1, n+res});
            }
            if (coolDown.size())
            {
                auto q_top = coolDown.front();
                // if front of queue has cooled down then add it back to max heap
                if (q_top.second == res)
                {
                    coolDown.pop();
                    pq.push(q_top.first);
                }
            }
        }
        
        return res;
        
    }
};