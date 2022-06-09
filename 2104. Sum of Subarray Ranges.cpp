class Solution {
public:
    long long f(vector<int>& a) {
        int n = a.size();
        vector<int> l(n, -1), r(n, n);
        stack<int> q;
        
        for (int i=0; i<n; ++i) {
            while (q.size() && a[i]>a[q.top()]) {
                r[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
        
        q = {};
        for (int i=n-1; i>=0; --i) {
            while (q.size() && a[i]>=a[q.top()]) {
                l[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
        
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            ans += (long long)(i-l[i])*(r[i]-i) * a[i];
        }
        return ans;
    }
    
    long long subArrayRanges(vector<int>& a) {
        auto pos = f(a);
        for (auto& x : a) x = -x;
        auto neg = f(a);
        return pos + neg;
    }
};