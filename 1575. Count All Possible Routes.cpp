class Solution {
public:
    
    int f[101][201];
    const int M = 1e9 + 7;
    
    int countRoutes(vector<int>& a, int start, int finish, int fuel) {
        int sp = a[start], ep = a[finish];
        sort(a.begin(), a.end());
        start = find(a.begin(), a.end(), sp) - a.begin();
        finish = find(a.begin(), a.end(), ep) - a.begin();
        memset(f, 0, sizeof(f));
        f[start][fuel] = 1;
        for (int gas=fuel; gas>0; --gas)
            for (int i=0; i<a.size(); ++i)
                if (f[i][gas]) {
                    for (int j=i-1; j>=0; --j)
                        if (a[i]-a[j] <= gas)
                            f[j][gas-(a[i]-a[j])] = (f[j][gas-(a[i]-a[j])] + f[i][gas]) % M;
                    for (int j=i+1; j<a.size(); ++j)
                        if (a[j]-a[i] <= gas)
                            f[j][gas-(a[j]-a[i])] = (f[j][gas-(a[j]-a[i])] + f[i][gas]) % M;
                }
        int ans = 0;
        for (int gas=0; gas<=fuel; ++gas)
            ans = (ans + f[finish][gas]) % M;
        return ans;
    }
};