class Solution {
public:

    int ans = INT_MIN;

    void dfs1(vector<vector<int>>& e, vector<int>& fa, int x, int pre) {
        fa[x] = pre;
        for (auto y : e[x])
            if (y != pre)
                dfs1(e, fa, y, x);
    }

    void dfs(vector<vector<int>>& e, vector<int>& at, vector<int>& a,
            int x, int t, int val, int fa) {
        if (at[x]>t) 
            val += a[x];
        else if (at[x]==t)
            val += a[x]/2;
        if (e[x].size()==1 && e[x][0]==fa) {
            ans = max(ans, val);
        } else {
            for (auto y : e[x])
                if (y != fa) {
                    dfs(e, at, a, y, t+1, val, x);
                }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> e(n);
        vector<int> fa(n, -1), at(n, INT_MAX);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        dfs1(e, fa, 0, -1);
        for (int x=bob, t=0; x!=-1; x=fa[x], ++t) at[x] = t;
        dfs(e, at, a, 0, 0, 0, -1);
        return ans;
    }
};