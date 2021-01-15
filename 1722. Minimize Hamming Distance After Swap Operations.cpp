class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& prs) {
        int n = a.size();
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        
        for (auto& pr : prs) {
            int x = find(pr[0]), y = find(pr[1]);
            if (x != y) {
                fa[x] = y;
            }
        }
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i)
            g[find(i)].push_back(i);
        int ans = 0;
        for (auto& grp : g)
            if (grp.size()) {
                unordered_map<int, int> src;
                for (auto x : grp) ++src[a[x]];
                for (auto x : grp)
                    if (src[b[x]]) {
                        ++ans;
                        --src[b[x]];
                    }
            }
        return b.size() - ans;
    }
};