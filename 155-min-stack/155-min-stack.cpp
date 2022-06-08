class MinStack {
private:
    vector<int> stack;
    int p_top = -1;
    int minElem = INT_MAX;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        p_top++;
        stack.push_back(val);
        minElem = min(minElem, val);
    }
    
    void pop() {
        if (p_top < 0) return;
        p_top--;
        int topElem = stack.back();
        stack.pop_back();
        
        if (topElem == minElem)
        {
            minElem = INT_MAX;
            for (int i = 0; i <= p_top; i++)
            {
                minElem = min(minElem, stack[i]);
            }
        }
    }
    
    int top() {
        if (p_top < 0) return -1;
        return stack.back();
    }
    
    int getMin() {
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */