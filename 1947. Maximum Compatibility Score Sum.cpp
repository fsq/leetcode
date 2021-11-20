class Solution {
public:
    int n, m, ans, sz;
    
    void dfs(vector<vector<int>>& scr, vector<int>& use, int i, int tot) {
        if (i == n) {
            ans = tot;
        } else {
            for (int j=0; j<m; ++j)
                if (!use[j] && tot+scr[i][j]+sz*(n-i-1)>ans) {
                    use[j] = true;
                    dfs(scr, use, i+1, tot+scr[i][j]);
                    use[j] = false;
                }
        }
            
    }
    
    int maxCompatibilitySum(vector<vector<int>>& a, vector<vector<int>>& b) {
        if (a.size() > b.size()) a.swap(b);
        n = a.size(), m = b.size(), sz=a[0].size();
        vector<vector<int>> scr(n, vector<int>(m));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                for (int k=0; k<a[i].size(); ++k)
                    if (a[i][k] == b[j][k])
                        ++scr[i][j];
            }
        
        ans = 0;
        vector<int> use(m);
        dfs(scr, use, 0, 0);
        return ans;
        
    }
};