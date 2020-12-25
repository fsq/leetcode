class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        vector<int> f(n);
        deque<int> q;
        int ans = 0;
        f[0] = a[0];
        q.push_back(0);
        for (int i=1; i<a.size(); ++i) {
            if (q.front() < i-k) q.pop_front();
            f[i] = a[i] + f[q.front()];
            while (!q.empty() && f[i]>f[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return f.back();
    }
};