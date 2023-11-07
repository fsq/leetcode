class Solution {
public:
    int n, root, total_coin;
    vector<vector<int>> e;
    vector<int> fa, sub1, d1, d2, f, c;

    void build(int x, int pre) {
        fa[x] = pre;
        if (c[x]) {
            ++d1[x];
            ++d2[x];
            ++sub1[x];
        }
        for (auto y : e[x])
            if (y != pre) {
                if (c[y]) ++d1[x];
                build(y, x);
                d2[x] += d1[y];
                sub1[x] += sub1[y];
            }
    }

    int build_root(int x) {
        int g = 0;
        if (sub1[x]==d2[x]) {
            return 0;
        }
        for (auto y : e[x])
            if (y!=fa[x] && sub1[y]>d1[y] /*otherwise no need to go down y*/) {
                g += build_root(y) + 2;
            }
        return g;
    }

    void buildf(int x) {
        if (x != root) {
            int fa_d1 = d1[fa[x]];
            if (fa[fa[x]]!=-1) fa_d1 += c[fa[fa[x]]];
            if (fa_d1+sub1[x]-c[x] == total_coin) {
                if (d1[x]==sub1[x])
                    f[x] = f[fa[x]];
                else
                    f[x] = f[fa[x]] - 2;
            } else {
                if (d1[x]==sub1[x])
                    f[x] = f[fa[x]] + 2;
                else
                    f[x] = f[fa[x]];
            }
        }
        for (auto y : e[x])
            if (y != fa[x])
                buildf(y);
    }

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        n = coins.size();
        c = coins;
        total_coin = accumulate(c.begin(), c.end(), 0);
        e.resize(n); fa.resize(n); sub1.resize(n);
        d1.resize(n); d2.resize(n); f.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        root = rand() % n;
        build(root, -1);
        f[root] = build_root(root);
        buildf(root);
        return *min_element(f.begin(), f.end());
    }
};