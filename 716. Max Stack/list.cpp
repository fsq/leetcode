class MaxStack {
public:
    
    // https://leetcode.com/problems/max-stack/description/
    // O(logn) for push/pop O(1) for top/peekMax/popMax
    // O(n) space
    
    /** initialize your data structure here. */
    list<int> stk;   // stack
    multiset<int, greater<int>> q; // max BST
    unordered_map<int, vector<list<int>::iterator>> pos; // position of x in stack
    
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push_front(x);
        pos[x].push_back(stk.begin());
        q.insert(x);
    }
    
    int pop() {
        auto ret = stk.front();
        stk.pop_front();
        q.erase(q.find(ret));
        pos[ret].pop_back();
        return ret;
    }
    
    int top() {
        return stk.front();
    }
    
    int peekMax() {
        return *q.begin();
    }
    
    int popMax() {
        auto ret = *q.begin();
        q.erase(q.begin());
        stk.erase(pos[ret].back());
        pos[ret].pop_back();
        return ret;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */