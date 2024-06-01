class Solution {
public:
    long long getMaxFunctionValue(vector<int>& a, long long k) {
        int n = a.size();

        vector<int> bs;
        for (int i=0; i<=63; ++i)
            if (k & (1ll<<i)) {
                bs.push_back(i);
            }
        int hb = bs.back(); // highest bit of k

        // from i, pass 2^j times, {score, last index}, excluding starting i
        vector<vector<pair<long long, int>>> f(n, vector<pair<long long, int>>(hb+1));
        for (int i=0; i<n; ++i) f[i][0] = {a[i], a[i]};

        for (int j=1; j<=hb; ++j) {
            for (int i=0; i<n; ++i) {
                auto p1 = f[i][j-1];
                auto p2 = f[p1.second][j-1];
                f[i][j] = {p1.first+p2.first, p2.second};
            }
        }

        long long ans = 0;
        // start as s
        for (int s=0; s<n; ++s) {
            long long tot = 0;
            int cur = s;
            for (auto b : bs) {
                tot += f[cur][b].first;
                cur = f[cur][b].second;
            }
            ans = max(ans, tot+s);
        }
        return ans;
    }
};