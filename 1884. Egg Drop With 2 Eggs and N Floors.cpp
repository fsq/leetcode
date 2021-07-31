class Solution {
public:
    vector<vector<int>> f;
    
    int func(int n, int x) {
        if (f[n][x] != INT_MAX) return f[n][x];
        if (x == 0)
            return f[n][x] = n;
        for (int i=1; i<=n; ++i) 
            f[n][x] = min(f[n][x], 1+max(func(i-1, x-1), func(n-i, x)));
        return f[n][x];
    }
    
    int twoEggDrop(int n) {
        f = vector<vector<int>>(n+1, vector<int>(2, INT_MAX));
        f[0][1] = f[0][0] = 0;
        f[1][0] = f[1][1] = 1;
        return func(n, 1);
    }
};