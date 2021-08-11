class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& a) {
        auto r = a, c = a;
        int n = a.size(), m = a[0].size();
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                if (j>0) r[i][j] += r[i][j-1];
                if (i>0) c[i][j] += c[i-1][j];
            }
        
        for (int l=min(n, m); l>=2; --l) {
            for (int i=0; i+l<=n; ++i)
                for (int j=0; j+l<=m; ++j) {
                    bool ok = true;
                    int tot = j==0 ? r[i][j+l-1] : r[i][j+l-1]-r[i][j-1];
                    for (int k=i+1; k<i+l; ++k) 
                        if ((j==0 ? r[k][j+l-1] : r[k][j+l-1]-r[k][j-1]) != tot) {
                            ok = false;
                            break;
                        }
                    if (!ok) continue;
                    
                     for (int k=j; k<j+l; ++k) 
                        if ((i==0 ? c[i+l-1][k] : c[i+l-1][k]-c[i-1][k]) != tot) {
                            ok = false;
                            break;
                        }
                    if (!ok) continue;
                    
                    int d1=0, d2=0;
                    for (int k=0; k<l; ++k) {
                        d1 += a[i+k][j+k];
                        d2 += a[i+k][j+l-1-k];
                    }
                    
                    if (d1!=tot || d2!=tot) continue;
                    return l;
                }
        }
        return 1;
    }
};