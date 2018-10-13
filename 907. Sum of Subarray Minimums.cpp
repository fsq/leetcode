class Solution {
public:
    const int M = 1e9+7;
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n, -1), nxt(n, n);
        
        stack<int> stk;
        for (int i=0; i<n; ++i) {
            while (!stk.empty() && a[stk.top()]>a[i]) {
                nxt[stk.top()] = i;
                stk.pop();
            }
            if (!stk.empty()) 
                pre[i] = stk.top();
            stk.push(i);
        }
        
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long len = (i-pre[i]) * (nxt[i]-i);
            ans = (ans + len * a[i]) % M;
        }
        return ans;
    }
};