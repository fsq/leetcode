class FrontMiddleBackQueue {
public:
    deque<int> a, b;
    
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        a.push_front(val);
        if (a.size() > b.size()) {
            b.push_front(a.back());
            a.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        if (a.size() > b.size()) {
            b.push_front(a.back());
            a.pop_back();
        }
    }
    
    void pushBack(int val) {
        b.push_back(val);
        if (b.size() > a.size()+1) {
            a.push_back(b.front());
            b.pop_front();
        }
    }
    
    int popFront() {
        if (a.empty() && b.empty()) return -1;
        int val = -1;
        if (a.empty()) {
            val = b.front();
            b.pop_front();
        } else {
            val = a.front();
            a.pop_front();
        }
        if (a.size()+1<b.size()) {
            a.push_back(b.front());
            b.pop_front();
        }
        return val;
    }
    
    int popMiddle() {
        if (a.empty() && b.empty()) return -1;
        int val = 0;
        if (a.size()==b.size()) {
            val = a.back();
            a.pop_back();
        } else {
            val = b.front();
            b.pop_front();
        }
        return val;
    }
    
    int popBack() {
        if (b.empty()) return -1;
        int val = b.back();
        b.pop_back();
        if (a.size() > b.size()) {
            b.push_front(a.back());
            a.pop_back();
        }
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */