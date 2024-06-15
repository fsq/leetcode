class Solution {
public:
    vector<int> fa;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    long long maximumSum(vector<int>& a) {
        int n = a.size();    
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
        // if a*b is perf sqr, b*c is perf sqr, then a*c is perf sqr.
        for (int i=1; i<=n; ++i) {
            for (int j=2; i*j*j<=n; ++j) {
                int y = i * j * j;
                int fx=find(i), fy=find(y);
                fa[fy] = fx;
            }
        }
        unordered_map<int, long long> acc;
        long long ans = 0;
        for (int i=1; i<=n; ++i) {
            long long& f = acc[find(i)];
            f += a[i-1];
            ans = max(ans, f);
        }
        return ans;
    }
};