class Solution {
public:
    
    const int M = 1e9 + 7;
    int c[10100][100];
    
    int comb(int n, int k) {
        if (k==0) return 1;
        if (n==k) return 1;
        if (c[n][k]) return c[n][k];
        return c[n][k] = (comb(n-1, k) + comb(n-1, k-1)) % M;
    }
    
    vector<int> waysToFillArray(vector<vector<int>>& qs) {
        int maxs = 0;
        memset(c, 0, sizeof(c));

        for (auto& q : qs)
            maxs = max(maxs, q[1]);
        
        vector<int> p;
        for (int i=2; i<=maxs; ++i) {
            bool ok = true;
            for (int j=2; j<=sqrt(i); ++j)
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            p.push_back(i);
        }
        
        vector<int> ans;
        for (auto& q : qs) {
            int n = q[0], k = q[1];
            long long tot = 1;
            for (auto prime : p) 
                if (k % prime == 0) {
                    int cnt = 0;
                    while (k % prime == 0) {
                        k /= prime;
                        ++cnt;
                    }
                    if (cnt) {
                        int cmb = comb(n+cnt-1, cnt);
                        tot = (tot * cmb) % M;
                    }
                    if (k == 1) break;
                }
            ans.push_back(tot);
        }
        return ans;
    }
};