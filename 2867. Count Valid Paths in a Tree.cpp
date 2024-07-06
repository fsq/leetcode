class Solution {
public:
    vector<vector<int>> e;
    vector<long long> s, t, f;

    bool isPrime(int x) {
        if (x == 1) return false;
        for (int i=2; i*i<=x; ++i)
            if (x % i == 0)
                return false;
        return true;
    }

    void dfs(int x, int pre) {
        long long tot = 0;
        for (auto y : e[x])
            if (y != pre) {
                dfs(y, x);
                tot += s[y];
            }
        bool prm = isPrime(x);
        if (prm) {
            t[x] = 1;
            long long two_branch=0, one_branch=0;
            for (auto y : e[x])
                if (y != pre) {
                    two_branch += s[y] * (tot - s[y]);
                    one_branch += s[y];
                    t[x] += s[y];
                }
            f[x] = one_branch + two_branch/2;
            s[x] = 0;
        } else {
            s[x] = 1;
            for (auto y : e[x])
                if (y != pre) {
                    f[x] += t[y] * (tot - s[y]) + t[y];
                    s[x] += s[y];
                    t[x] += t[y];
                }
        }
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        e.resize(n + 1);
        s.resize(n + 1);
        t.resize(n + 1);
        f.resize(n + 1);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        dfs(1, -1);
        long long ans = accumulate(f.begin(), f.end(), 0ll);
        return ans;
    }
};