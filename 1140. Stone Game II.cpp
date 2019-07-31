class Solution {
public:
    int stoneGameII(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 0);
        vector<vector<int>> f(n+2, vector<int>(n+2));
        vector<int> s(n+1);
        partial_sum(a.begin()+1, a.end(), s.begin()+1);
        for (int i=n; i>=1; --i) 
            for (int m=1; m<=n; ++m)
                for (int k=1; k<=2*m && i+k-1<=n; ++k)
                    f[i][m] = max(f[i][m], s[i+k-1]-s[i-1] + s[n]-s[i+k-1] - f[i+k][max(k, m)]);
        return f[1][1];
    }
};