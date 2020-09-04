class Solution {
public:
    const int M = 1e9 + 7;
    int c[1001][1001];
    
    long long dfs(vector<int>& a) {
        if (a.size()<=1) return 1;
        long long ans = 1;
        vector<int> ls, gt;
        for (int i=1; i<a.size(); ++i) 
            if (a[i] > a[0])
                gt.push_back(a[i]);
            else 
                ls.push_back(a[i]);
        ans = c[ls.size()+gt.size()][ls.size()];
        ans = ans * (dfs(ls) * dfs(gt) % M) % M;
        return ans;
    }
    
    int numOfWays(vector<int>& a) {
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        int n = a.size();
        for (int i=1; i<=n; ++i) {
            c[i][0] = 1;
            for (int j=1; j<=i; ++j) 
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
        }
        
        return (dfs(a) + M - 1) % M;
    }
};