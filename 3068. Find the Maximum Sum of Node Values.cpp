class Solution {
public:
    vector<vector<long long>> e, f;
    int k;

    void dp(vector<int>& a, int x, int pre) {
        long long& f0 = f[x][0];
        long long& f1 = f[x][1];
        f1 = -1;
        for (auto y: e[x])
            if (y != pre) {
                dp(a, y, x);
                long long g0 = f0 + max(f[y][0], f[y][1]);
                if (f1 != -1)
                    g0 = max(g0, f1 + max(f[y][0]-a[y]+(a[y]^k), f[y][1]-(a[y]^k)+a[y]));
                long long g1 = f0 + max(f[y][0]-a[y]+(a[y]^k), f[y][1]-(a[y]^k)+a[y]);
                if (f1 != -1)
                    g1 = max(g1, f1 + max(f[y][0], f[y][1]));
                f0 = g0;
                f1 = g1;
            }
        f0 += a[x];
        if (f1 != -1)
            f1 += a[x] ^ k;
        else
            f1 = 0xff3f3f3f3f3f3f3f;
    }

    long long maximumValueSum(vector<int>& a, int _k, vector<vector<int>>& edges) {
        k = _k;
        int n = a.size();
        e.resize(n);
        f = vector<vector<long long>>(n, vector<long long>(2));
        for (auto& pr: edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        dp(a, 0, -1);
        return max(f[0][0], f[0][1]);
    }
};