class Solution {
public:
    int n;
    int f[51][51];
    const int INF = 0x3f3f3f3f;
    
    int dp(const vector<int>& a, int l, int r) {
        if (l+2 > r) return 0;
        if (l+2 == r) return a[l]*a[l+1]*a[r];
        if (f[l][r]) return f[l][r];
        
        f[l][r] = INF;
        for (int k=l+1; k<r; ++k)
            f[l][r] = min(f[l][r], dp(a,l,k)+dp(a,k,r)+a[l]*a[r]*a[k]);
        return f[l][r];
    }
    
    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
        memset(f, 0, sizeof(f));
        return dp(a, 0, n-1);
    }
};