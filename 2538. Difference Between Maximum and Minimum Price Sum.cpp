class Solution {
public:
    vector<long long> down, up;
    vector<vector<long long>> e;

    long long dfs1(int x, vector<int>& val, int fa) {
        long long a = 0;
        for (auto y : e[x]) 
            if (y != fa) {
                a = max(a, dfs1(y, val, x));
            }
        down[x] = a + val[x];
        return down[x];
    }

    void dfs2(int x, vector<int>& val, long long above, int fa) {
        up[x] = above + val[x];
        long long a=0, b=0;
        for (auto y : e[x]) 
            if (y != fa) {
                auto c = down[y];
                if (c >= a) {
                    b = a;
                    a = c;
                } else if (c > b) {
                    b = c;
                }
            }
        for (auto y : e[x])
            if (y != fa) {
                if (down[y]==a) {
                    dfs2(y, val, max(b+val[x], up[x]), x);
                } else {
                    dfs2(y, val, max(a+val[x], up[x]), x);
                }
            }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        down.resize(n);
        up.resize(n);
        e.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        int root = rand() % n;
        dfs1(root, price, -1);
        dfs2(root, price, 0, -1);
        long long ans = 0;
        for (int r=0; r<n; ++r) {
            long long sum = max(down[r], up[r]) - price[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};