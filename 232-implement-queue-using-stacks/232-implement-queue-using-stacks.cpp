class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int size;
public:
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        s1.push(x);
        size++;
    }
    
    int pop() {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        size--;
        return res;
    }
    
    int peek() {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    
    bool empty() {
        return !size;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */