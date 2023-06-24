class Solution {
public:
    vector<int> fa;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    int minScore(int n, vector<vector<int>>& roads) {
        fa.resize(n+1);
        iota(fa.begin(),fa.end(), 0);
        for (auto& pr: roads) {
            auto x = pr[0], y = pr[1], fx=find(x), fy=find(y);
            if (fx != fy) {
                fa[fx] = fy;
            }
        }
        int ans = INT_MAX, cc = find(1);
        for (auto& pr : roads) {
            auto fx=find(pr[0]), fy=find(pr[1]);
            if (fx==cc && fy==cc) 
                ans = min(ans, pr[2]);
        }
        return ans;
    }
};