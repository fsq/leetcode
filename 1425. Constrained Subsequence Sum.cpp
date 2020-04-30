class Solution {
public:
    int constrainedSubsetSum(vector<int>& a, int k) {
        int n = a.size();
        deque<int> q;
        vector<int> f(n);
        f[0] = a[0];
        q.push_back(0);
        for (int i=1; i<n; ++i) {
            while (q.front()<i-k) q.pop_front();
            f[i] = max(a[i], f[q.front()] + a[i]);
            while (!q.empty() && f[i]>=f[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return *max_element(f.begin(), f.end());
    }
};