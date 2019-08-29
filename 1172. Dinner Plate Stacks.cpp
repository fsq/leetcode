class DinnerPlates {
public:
    map<int, stack<int>> s;
    set<int> nf;
    int cap;
    
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (nf.empty())
            nf.insert(s.size());
        s[*nf.begin()].push(val);
        if (s[*nf.begin()].size()==cap)
            nf.erase(nf.begin());
    }
    
    int pop() {
        while (s.size() && !s.rbegin()->second.size())
            s.erase(s.rbegin()->first);
        if (s.empty()) return -1;
        return popAtStack(s.rbegin()->first);
    }
    
    int popAtStack(int index) {
        if (!s.count(index) || s[index].empty()) return -1;
        int ret = s[index].top();
        s[index].pop();
        nf.insert(index);
        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */