class Solution {
public:
    
    const int INF = 0x3f3f3f3f;
    
    int minChanges(vector<int>& a, int k) {
        vector<unordered_map<int, int>> freq(k);
        vector<int> tot(k);
        for (int i=0; i<a.size(); ++i)
            ++freq[i % k][a[i]], ++tot[i % k];

        vector<vector<int>> f(k+1, vector<int>(1024, INF));
        f[0][0] = 0;
        int prev_min = 0;
        for (int i=1; i<=k; ++i) {
            int cur_min = INF;
            for (int j=0; j<1024; ++j) {
                f[i][j] = prev_min + tot[i-1];
                for (auto& pr : freq[i-1]) {
                    f[i][j] = min<int>(f[i][j], f[i-1][j^pr.first] + tot[i-1] - pr.second);
                }             
                cur_min = min(cur_min, f[i][j]);
            }
            prev_min = cur_min;
        }
        return f[k][0];
    }
};