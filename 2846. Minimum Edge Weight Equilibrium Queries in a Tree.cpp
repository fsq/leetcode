class Solution {
public:
    int root, h = 0, hp = 0;
    vector<vector<pair<int, int>>> e;
    vector<int> pa;
    vector<int> dp;
    vector<vector<int>> ws;

    void find_h(int x, int fa, int d, vector<int>& cur_w) {
        h = max(h, d);
        dp[x] = d;
        pa[x] = fa;
        ws[x] = cur_w;
        for (auto [y, w] : e[x])
            if (y != fa) {
                ++cur_w[w];
                find_h(y, x, d + 1, cur_w);
                --cur_w[w];
            }
    }

    int calc(vector<vector<int>>& f, int tu, int tv) {
        int u = tu, v = tv;
        if (dp[u] < dp[v])
            swap(u, v);
        int gap = dp[u] - dp[v];
        for (int i = hp; i >= 0; --i)
            if (gap & (1 << i)) {
                u = f[u][i];
            }
        for (int i = hp; i >= 0 && u != v; --i)
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        if (u != v) {
            u = v = f[u][0];
        }
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i)
            cnt[i] = ws[tu][i] + ws[tv][i] - 2 * ws[u][i];
        return accumulate(cnt.begin(), cnt.end(), 0) -
               *max_element(cnt.begin(), cnt.end());
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges,
                                     vector<vector<int>>& queries) {
        root = rand() % n;
        e.resize(n);
        pa.resize(n);
        dp.resize(n);
        ws.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back({pr[1], pr[2] - 1});
            e[pr[1]].push_back({pr[0], pr[2] - 1});
        }
        vector<int> cur_w(26);
        find_h(root, -1, 1, cur_w);
        hp = ceil(log2(h));
        vector<vector<int>> f(n, vector<int>(32, -1));
        for (int i = 0; i < n; ++i)
            if (i != root) {
                f[i][0] = pa[i];
            }
        for (int p = 1; p <= hp; ++p) {
            for (int i = 0; i < n; ++i) {
                if (f[i][p-1] != -1)
                    f[i][p] = f[f[i][p-1]][p - 1];
            }
        }
        vector<int> ans;
        for (auto& pr : queries) {
            ans.push_back(calc(f, pr[0], pr[1]));
        }
        return ans;
    }
};