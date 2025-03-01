class Solution {
public:
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans, fa(n);
        iota(fa.begin(), fa.end(), 1);
        int cc = n - 1;
        for (auto& pr : queries) {
            int x=pr[0], y=pr[1];
            if (fa[x] != fa[y]) {
                while (x < y) {
                    int fx = fa[x];
                    fa[x] = y;
                    --cc;
                    x = fx;
                }
                ++cc;
            }
            ans.push_back(cc);
        }
        return ans;
    }
};