class MyCircularQueue {
private:
    int size;
    vector<int> arr;
    int curr_size;
    int front;
    int tail;
public:


    MyCircularQueue(int k) {
        size = k;
        curr_size = 0;
        front = 0;
        tail = -1;
        arr = vector(k, -1);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail = (tail+1)%size;
        arr[tail] = value;
        curr_size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        arr[front] = -1;
        front = (front+1)%size;
        curr_size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return arr[tail];
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return size == curr_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */