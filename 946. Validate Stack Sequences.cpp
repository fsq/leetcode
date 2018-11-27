class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int> stk;
        for (auto x : popped) {
            while (i<pushed.size() && (stk.empty() || stk.top()!=x)) 
                stk.push(pushed[i++]);
            if (stk.top()!=x) return false;
            stk.pop();
        }
        return true;
    }
};