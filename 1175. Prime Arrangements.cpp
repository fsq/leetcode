class Solution {
public:
    const int M = 1e9 + 7;
    int numPrimeArrangements(int n) {
        vector<int> vis(n+1), p;
        for (int i=2; i<=n; ++i) {
            if (!vis[i]) p.push_back(i);
            for (int j=0; j<p.size() && p[j]*i<=n; ++j) {
                vis[p[j]*i] = true;
                if (i % p[j]==0) break;
            }
        }
        long long ans = 1;
        
        for (int i=2; i<=p.size(); ++i) 
            ans = ans * i % M;
        for (int i=2; i<=n-p.size(); ++i)
            ans = ans * i % M;
        return ans;
    }
};