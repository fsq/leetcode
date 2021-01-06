class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, long long> m;
        int mx = 0;
        for (auto x : deliciousness) {
            ++m[x];
            mx = max(x, mx);
        }
        long long ans = 0;
        for (auto& pr : m) {
            int x = pr.first;
            for (int i=0; (1<<i)<=x + mx; ++i) {
                int y = (1<<i) - x;
                if (y>=x && m.count(y)) {
                    if (x==y)
                        ans = (ans + pr.second * (pr.second-1) / 2) % M;
                    else 
                        ans = (ans + pr.second * m[y]) % M;
                }
            }
        }
        return ans;
    }
};