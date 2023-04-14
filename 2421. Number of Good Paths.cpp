class Solution {
public:
    vector<int> fa;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> e(n);
        for (auto& pr : edges) {
            if (vals[pr[0]]>=vals[pr[1]]) e[pr[0]].push_back(pr[1]);
            if (vals[pr[0]]<=vals[pr[1]]) e[pr[1]].push_back(pr[0]);
        }
    
        map<int, vector<int>> m;
        for (int i=0; i<n; ++i) m[vals[i]].push_back(i);

        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);

        int ans = 0;
        for (auto& [v, us] : m) {
            for (auto u : us)
                for (auto y : e[u]) {
                    int fx=find(u), fy=find(y);
                    if (fx != fy) fa[fx] = fy;
                }
            unordered_map<int, int> cnt;
            for (auto u : us) ++cnt[find(u)];
            for (auto& [_, c] : cnt) ans += c * (c-1) / 2 + c;
        }
        return ans;
    }
};