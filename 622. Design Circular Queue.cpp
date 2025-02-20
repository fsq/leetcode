class MyCircularQueue {
public:
    vector<int> a;
    int n = 0, i = 0;

    MyCircularQueue(int k) {
        a.resize(k);
    }
    
    bool enQueue(int value) {
        if (n == a.size()) return false;
        a[i] = value;
        i = (i + 1) % a.size();
        ++n;
        return true;
    }
    
    bool deQueue() {
        if (n == 0) return false;
        --n;
        return true;
    }
    
    int Front() {
        if (n == 0) return -1;
        int j = (i - n + a.size()) % a.size();
        return a[j];
    }
    
    int Rear() {
        if (n == 0) return -1;
        return a[(i-1+a.size()) % a.size()];
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    bool isFull() {
        return n == a.size();
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