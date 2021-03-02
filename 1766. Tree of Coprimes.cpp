class Solution {
public:
    vector<int> ans;
    vector<int> h;
    
    void dfs(vector<int>& a, vector<vector<int>>& e, vector<vector<int>>& an, int dp, int x, int fa) {
        h[x] = dp;
        int ancestor = -1, ah = -1;
        for (int i=1; i<=50; ++i)
            if (an[i].size() && gcd(a[x], i)==1) {
                if (h[an[i].back()] > ah) {
                    ancestor = an[i].back();
                    ah = h[ancestor];
                }
            }
        if (ancestor != -1) ans[x] = ancestor;
        
        an[a[x]].push_back(x);
        for (auto y : e[x])
            if (y != fa) {
                dfs(a, e, an, dp + 1, y, x);
            }
        an[a[x]].pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& a, vector<vector<int>>& edges) {
        int n = a.size();
        ans = vector<int>(n, -1);
        h.resize(n);
        vector<vector<int>> e(n);
        for (auto& eg : edges) {
            e[eg[0]].push_back(eg[1]);
            e[eg[1]].push_back(eg[0]);
        }
        vector<vector<int>> an(51);
        dfs(a, e, an, 0, 0, -1);
        return ans;
    }
};