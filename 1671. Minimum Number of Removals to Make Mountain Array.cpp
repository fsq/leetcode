class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> f(n, 1), g(n, 1);
        f[0] = 1;
        for (int i=1; i<n; ++i)
            for (int j=0; j<i; ++j)
                if (a[j]<a[i])
                    f[i] = max(f[i], f[j]+1);
        
        g[n-1] = 1;
        for (int i=n-2; i>=0; --i)
            for (int j=i+1; j<n; ++j)
                if (a[i]>a[j])
                    g[i] = max(g[i], g[j]+1);
        int ans = 0;
        for (int i=1; i+1<n; ++i) 
            if (f[i]>1 && g[i]>1)
                ans = max(ans, f[i]+g[i]-1);

        return n - ans;
    }
};