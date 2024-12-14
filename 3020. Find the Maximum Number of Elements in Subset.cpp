class Solution {
public:

    unordered_map<int, int> m, f;

    int dfs(int x) {
        if (f.count(x)) return f[x];
        if (x==1) {
            return m[x] - !(m[x] & 1);
        }

        int y = sqrt(x);
        if (y*y != x) return f[x]=1;
        if (m[y] >= 2) {
            f[x] = dfs(y) + 2;
        } else {
            f[x] = 1;
        }
        return f[x];
    }

    int maximumLength(vector<int>& a) {
        for (auto x : a) ++m[x];
        int ans = 1;
        for (auto x : a) ans = max(ans, dfs(x));
        return ans;
    }
};