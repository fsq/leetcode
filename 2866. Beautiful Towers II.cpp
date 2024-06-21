class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        int n = a.size();
        vector<long long> l(n, -1), r(n, n);
        vector<int> q;
        for (int i=0; i<n; ++i) {
            while (q.size() && a[q.back()] > a[i]) {
                r[q.back()] = i;
                q.pop_back();
            }
            if (q.size()) {
                l[i] = q.back();
            }
            q.push_back(i);
        }
        vector<long long> lh(n), rh(n);
        for (int i=0; i<n; ++i) {
            long long pre = l[i];
            lh[i] = (pre==-1 ? 0 : lh[pre]) + (i - pre) * a[i];
        }
        long long ans = 0;
        for (int i=n-1; i>=0; --i) {
            long long nxt = r[i];
            rh[i] = (nxt==n ? 0 : rh[nxt]) + (nxt - i) * a[i];
            ans = max(ans, lh[i]+rh[i]-a[i]);
        }
        return ans;
    }
};