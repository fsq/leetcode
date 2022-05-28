class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& mtg, int firstPerson) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        fa[firstPerson] = 0;
        map<int, vector<vector<int>>> m;
        for (auto& pr : mtg) {
            int x = pr[0], y = pr[1];
            m[pr[2]].push_back({x, y});
        }
        for (auto& pr : m) {
            auto& g = pr.second;
            for (auto& pr : g) {
                int x = pr[0], y = pr[1];
                int fx=find(x), fy=find(y);
                if (fx != fy) fa[fy] = fx;
            }
            for (auto& pr : g) {
                int x = pr[0], y = pr[1];
                if (find(x)!=find(0)) fa[x]=x;
                if (find(y)!=find(0)) fa[y]=y;
            }
        }
        vector<int> ans;
        for (int i=0; i<n; ++i)
            if (find(i) == find(0))
                ans.push_back(i);
        return ans;
    }
};