class Solution {
public:
    vector<int> p = {2,3,5,7,11,13,17,19,23,29};
    const int M = 1e9 + 7;
    
    int numberOfGoodSubsets(vector<int>& a) {
        vector<int> cnt(31);
        
        for (auto x : a) ++cnt[x];
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        
        vector<long long> f(1<<10), g=f;
        g[0] = f[0] = 1;
        for (int i=a[0]==1 ? 1: 0; i<a.size(); ++i) {
            int msk = 0;
            bool dup = false;
            for (int j=0; j<p.size(); ++j)
                if (a[i] % p[j]==0) {
                    if (a[i] % (p[j]*p[j]) == 0) {
                        dup = true;
                        break;
                    } else {
                        msk |= 1 << j;   
                    }                    
                }
            if (dup) continue;
            for (int j=0; j<(1<<p.size()); ++j) 
                if ((j & msk) == msk)
                    f[j] = (g[j] + g[j^msk]*cnt[a[i]]%M) % M;  
            g = f;
        }
        long long ans = 0;
        for (int i=1; i<(1<<p.size()); ++i) ans = (ans + g[i]) % M;
        for (int i=0; i<cnt[1]; ++i) ans = ans * 2 % M;
        return ans;
    }
};