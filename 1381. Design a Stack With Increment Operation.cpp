class CustomStack {
public:
    stack<int> stk;
    vector<int> s;
    int ms;
    CustomStack(int maxSize) {
        ms = maxSize;
        s.resize(ms);
    }
    
    void push(int x) {
        if (stk.size() < ms) stk.push(x);
    }
    
    int pop() {
        if (stk.empty()) return -1;
        int ret = stk.top();
        stk.pop();
        int n = stk.size();
        ret += s[n];
        if (n > 0) s[n-1] += s[n];
        s[n] = 0;
        return ret;
    }
    
    void increment(int k, int val) {
        if (stk.empty()) return;
        s[min<int>(stk.size(), k)-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */