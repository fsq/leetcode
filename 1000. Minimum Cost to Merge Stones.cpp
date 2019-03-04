class Solution {
public:
    vector<int> s;
    vector<vector<int>> f;
    int n, k;
    const int INF = 0x3f3f3f3f;
    
    int sum(int l, int r) {
        return l==0 ? s[r] : s[r]-s[l-1];
    }
    
    int dp(const vector<int>& a, int l, int r) {
        if (f[l][r] != 0) return f[l][r];
        
        if ((r-l) % (k-1) != 0) 
            f[l][r] = INF;
        else if (r-l+1 == k) 
            f[l][r] = sum(l, r);
        else if (l==r)
            f[l][r] = 0;
        else {   
            vector<vector<int>> g(r-l+2, vector<int>(k+1, INF));

            g[0][0] = 0;
            for (int i=1; i<=r-l+1; ++i) 
                for (int j=1+(i==r-l+1);j<=k; ++j) 
                    for (int pre=0; pre<i; ++pre) 
                        if (g[pre][j-1] != INF)
                            g[i][j] = min(g[i][j], g[pre][j-1] + dp(a, l+pre, l+i-1)+sum(l+pre, l+i-1));
            f[l][r] = g.back()[k];
            
        }
        return f[l][r];
    }
    
    int mergeStones(vector<int>& a, int _k) {
        k = _k;
        n = a.size();
        if ((n-1) % (k-1) != 0) return -1;
        s.resize(n);
        partial_sum(a.begin(), a.end(), s.begin());
        
        f = vector<vector<int>>(n+1, vector<int>(n+1));
        return dp(a, 0, n-1);
    }
};