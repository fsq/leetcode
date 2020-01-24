class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for (int i=0; i+3<=n; ++i)
            for (int j=0; j+3<=m; ++j) {
                vector<int> vis(10);
                bool ok = true;
                
                for (int r=i; r<=i+2; ++r) {
                    for (int c=j; c<=j+2; ++c)
                        if (a[r][c]<=0 || a[r][c]>9 || vis[a[r][c]])  {
                            ok = false;
                            break;
                        } else {
                            vis[a[r][c]] = true;
                        }
                    if (!ok) break;
                }
                if (!ok) continue;
                int s = a[i][j] + a[i+1][j] + a[i+2][j];
                for (int r=i; r<=i+2; ++r)
                    if (a[r][j]+a[r][j+1]+a[r][j+2]!=s) {
                        ok = false;
                        break;
                    }
                if (!ok) continue;
                for (int c=j; c<=j+2; ++c)
                    if (a[i][c]+a[i+1][c]+a[i+2][c]!=s) {
                        ok = false;
                        break;
                    }
                if (!ok) continue;
                if (a[i][j]+a[i+1][j+1]+a[i+2][j+2]==s && a[i][j+2]+a[i+1][j+1]+a[i+2][j]==s) {
                    ++ans;
                }
            }
        return ans;
    }
};