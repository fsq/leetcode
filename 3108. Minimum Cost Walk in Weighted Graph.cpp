class Solution {
public:
    vector<int> fa, cost;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        fa.resize(n);
        cost.resize(n, -1);
        iota(fa.begin(), fa.end(), 0);
        for (auto& pr : edges) {
            int x = pr[0], y = pr[1];
            int fx=find(x), fy=find(y);
            if (fx != fy) {
                fa[fy] = fx;
                cost[fx] &= pr[2] & cost[fy];
            } else {
                cost[fx] &= pr[2];
            }
        }
        vector<int> ans;
        for (auto& q : query) {
            int fx=find(q[0]), fy=find(q[1]);
            if (fx == fy)
                ans.push_back(cost[fx]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};