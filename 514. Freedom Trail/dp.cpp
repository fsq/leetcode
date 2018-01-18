class Solution {
public:
    
    // https://leetcode.com/problems/freedom-trail/description/
    // DP
    // O(m*n^2) time O(n) space, m=key.size, n=ring.size
    // f[i][j] = mincost to spell first i keys, where i-th key stops at ring[j]
    // f[i][j] = min(f[i-1][p]+dist(p, j)), where ring[j]==key[i], ring[p]==key[i-1]
    
    int findRotateSteps(string ring, string key) {
        if (key.empty()) return 0;
        int n = ring.size();
        
        // shortest distance between two buttons
        auto dist = [=](int x, int y) {return min(abs(x-y), n-abs(x-y)); };
        
        int m = key.size();
        vector<int> f(n, INT_MAX), pre=f;
        
        for (int i=0; i<n; ++i)
            if (ring[i]==key[0])
                pre[i] = dist(i, 0);
        
        for (int k=1; k<m; ++k) {
            fill(f.begin(), f.end(), INT_MAX);
            for (int to=0; to<n; ++to)
                if (ring[to]==key[k]) 
                    for (int from=0; from<n; ++from)
                        if (ring[from]==key[k-1]) 
                            f[to] = min(f[to], pre[from]+dist(from, to));
            pre.swap(f);
        }
        return *min_element(pre.begin(), pre.end())+key.size();
    }
};