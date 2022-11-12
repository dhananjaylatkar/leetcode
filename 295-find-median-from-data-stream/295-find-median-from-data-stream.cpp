class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;

public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        if (max_heap.size() && min_heap.size() && max_heap.top() > -min_heap.top())
        {
            min_heap.push(-max_heap.top());
            max_heap.pop();
        }
        
        if (max_heap.size() - min_heap.size() == 2)
        {
            int tmp = max_heap.top();
            max_heap.pop();
            
            min_heap.push(-tmp);
        }
        
        if (min_heap.size() - max_heap.size() == 2)
        {
            int tmp = -min_heap.top();
            min_heap.pop();
            max_heap.push(tmp);
        }
    }
    
    double findMedian() {
        int n1 = max_heap.size();
        int n2 = min_heap.size();
        if (n1 == 0) return 0;
        if (n1 == n2) 
        {
            return (max_heap.top()-min_heap.top())/2.0;
        }
        else if (n1 > n2)
        {
            return max_heap.top();
        }
        else
        {
            return -min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */