class Solution {
public:

    void dfs(vector<vector<int>>& e, vector<int>& vis, int x) {
        vis[x] = true;
        for (auto y : e[x])
            if (!vis[y]) {
                dfs(e, vis, y);
            }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& re) {
        vector<int> vis(n);
        vector<vector<int>> e(n);
        unordered_set<int> st(re.begin(), re.end());
        for (auto& pr : edges) 
            if (!st.count(pr[0]) && !st.count(pr[1])) {
                e[pr[0]].push_back(pr[1]);
                e[pr[1]].push_back(pr[0]);
            }
        dfs(e, vis, 0);
        return accumulate(vis.begin(), vis.end(), 0);
    }
};