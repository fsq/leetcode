class Solution {
public:
    vector<int> s, p; // accumulated sum of each node
    vector<vector<int>> e, f;

    bool dfs(int x, int target, int pre) {
        if (x==target) {
            s[x] += p[x];
            return true;
        } else {
            for (auto y : e[x])
                if (y != pre && dfs(y, target, x)) {
                    s[x] += p[x];
                    return true;
                }
            return false;
        }
    }

    void dp(int x, int pre=-1) {
        if (f[x][0] != -1) return;
        f[x][0] = s[x];
        f[x][1] = s[x]/2;
        for (auto y : e[x])
            if (y != pre) {
                dp(y, x);
                f[x][0] += min(f[y][0], f[y][1]);
                f[x][1] += f[y][0];
            }
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        p = price;
        s.resize(n);
        e.resize(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        for (auto& trip : trips) {
            dfs(trip[0], trip[1], -1);
        }
        
        f = vector<vector<int>>(n, vector<int>(2, -1));
        dp(0);
        return min(f[0][1], f[0][0]);
    }
};