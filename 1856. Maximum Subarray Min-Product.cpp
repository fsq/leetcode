class Solution {
public:
    int maxSumMinProduct(vector<int>& a) {
        int n = a.size();
        vector<int> nxt(n, n), pre(n, -1);
        
        stack<int> s, t;
        for (int i=0; i<n; ++i) {
            while (s.size() && a[i]<a[s.top()]) {
                nxt[s.top()] = i;
                s.pop();
            }
            s.push(i);
            while (t.size() && a[n-i-1]<a[t.top()]) {
                pre[t.top()] = n-i-1;
                t.pop();
            }
            t.push(n-i-1);
        }
        
        vector<long long> ps(n);
        ps[0] = a[0];
        for (int i=1; i<n; ++i) ps[i] = ps[i-1] + a[i];
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long seg = ps[nxt[i]-1] - (pre[i]==-1 ? 0 : ps[pre[i]]);
            ans = max(ans, a[i] * seg);
        }
        return ans % 1000000007;
    }
};