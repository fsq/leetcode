class Solution {
public:
    vector<int> ans;
    vector<int> cnt;
    
    void dfs(vector<vector<int>>& e, string& s, int x, int fa) {
        ans[x] = cnt[s[x]-'a']++;
        for (auto y : e[x])
            if (y!=fa) {
                dfs(e, s, y, x);
            }
        ans[x] = cnt[s[x]-'a'] - ans[x];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        cnt.resize(26);
        vector<vector<int>> e(n);
        for (auto& p : edges) 
            e[p[0]].push_back(p[1]), e[p[1]].push_back(p[0]);
        dfs(e, labels, 0, -1);
        return ans;
    }
};