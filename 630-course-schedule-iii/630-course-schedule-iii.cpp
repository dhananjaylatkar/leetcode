class Solution {
public:
    static bool mycmp (vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), mycmp);
        
        priority_queue<int> pq;
        int time = 0;
        for (auto c: courses)
        {
            // cout << c[0] << endl;
            if (time+c[0] <= c[1]) // take the course
            {
                time += c[0];
                pq.push(c[0]);
            }
            else
            {
                if (!pq.size()) continue;
                // try to replace with prev max
                int top = pq.top();
                
                if (top > c[0])
                {
                    time -= top;
                    time += c[0];
                    pq.pop();
                    pq.push(c[0]);
                }
            }
        }
        
        return pq.size();
    }
};