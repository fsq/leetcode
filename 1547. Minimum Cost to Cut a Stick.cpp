class Solution {
public:
    
    int f[103][103];
    
    int dfs(vector<int>& a, int l, int r) {
        if (r <= l+1) return 0;
        int& ans = f[l][r];
        if (ans != -1) return ans;
        ans = 0x3f3f3f3f;
        for (int k=l+1; k<r; ++k) {
            ans = min(ans, a[r]-a[l] + dfs(a, l, k) + dfs(a, k, r));
        }
        return ans;
    }
    
    int minCost(int n, vector<int>& a) {
        a.insert(a.begin(), 0);
        a.push_back(n);
        sort(a.begin(), a.end());
        memset(f, -1, sizeof(f));
        return dfs(a, 0, a.size()-1);
    }
};