class Solution {
public:
    int ans, k;
    unordered_map<int, unordered_set<int>> g;

    int dfs1(vector<vector<int>>& e, int x, int fa) {
        int cnt = 0;
        for (auto y : e[x]) 
            if (y != fa) {
                if (g[x].count(y)) ++cnt;
                cnt += dfs1(e, y, x);
            }
        return cnt;
    }

    void dfs(vector<vector<int>>& e, int x, int fa, int cur) {
        if (cur >= k) ++ans;
        for (auto y : e[x])
            if (y != fa) {
                int nxt = cur;
                if (g[x].count(y)) --nxt;
                if (g[y].count(x)) ++nxt;
                dfs(e, y, x, nxt);
            }
    }


    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int _k) {
        vector<vector<int>> e(edges.size()+1);
        for (auto &pr : guesses) {
            g[pr[0]].insert(pr[1]);
        }
        for (auto& eg : edges) {
            e[eg[0]].push_back(eg[1]);
            e[eg[1]].push_back(eg[0]);
        }
        ans = 0;
        k = _k;
        int cur = dfs1(e, 0, -1);
        dfs(e, 0, -1, cur);
        return ans;
    }  
};