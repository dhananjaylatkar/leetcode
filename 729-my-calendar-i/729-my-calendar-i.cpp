class MyCalendar {
public:
    map<int, int> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        intervals[start]++;
        intervals[end]--;
        int sum = 0;
        for (auto it: intervals)
        {
            sum += it.second;
            if (sum > 1)
            {
                intervals[start]--;
                intervals[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */