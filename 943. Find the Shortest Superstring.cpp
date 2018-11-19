class Solution {
public:
    string shortestSuperstring(vector<string>& a) {
        int n = a.size();
        vector<vector<int>> d(n, vector<int>(n));
        for (int i=0; i<n; ++i) 
            for (int j=0; j<n; ++j) 
                if (i!=j)
                    for (int len=a[j].size()-1; len>=0; --len) 
                        if (equal(a[j].begin(), a[j].begin()+len, a[i].end()-len)) {
                            d[i][j] = a[j].size() - len;
                            break;
                        }
            
        
        vector<vector<int>> f(n, vector<int>(1<<n, INT_MAX)), g = f;
    
        for (int vis=1; vis<(1<<n); ++vis) 
            for (int i=0; i<n; ++i)
                if ((vis>>i) & 1) {
                    int pre = vis ^ (1<<i);
                    if (pre==0) 
                        f[i][vis] = a[i].size();
                    else 
                        for (int j=0; j<n; ++j)
                            if (((pre>>j) & 1) && f[j][pre]!=INT_MAX && f[j][pre]+d[j][i]<f[i][vis]) {
                                f[i][vis] = f[j][pre] + d[j][i];
                                g[i][vis] = j;
                            }
                }
        
        int mind = INT_MAX, pre = 0;
        for (int i=0; i<n; ++i)
            if (f[i][(1<<n)-1]<mind) {
                mind = f[i][(1<<n)-1];
                pre = i;
            }
        
        vector<int> seq;
        for (int vis=(1<<n)-1; vis; ) {
            seq.push_back(pre);
            int nxt = g[pre][vis];
            vis ^= 1<<pre;
            pre = nxt;
        }
        reverse(seq.begin(), seq.end());
        
        string ans = a[seq[0]];
        for (int i=1; i<n; ++i) {
            int l = d[seq[i-1]][seq[i]];
            ans += a[seq[i]].substr(a[seq[i]].size()-l);
        }
        return ans;
    }
};