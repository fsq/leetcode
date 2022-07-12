class Solution {
public:
    long long maxRunTime(int n, vector<int>& a) {
        long long s = accumulate(a.begin(), a.end(), 0ll);      
        long long l = 1, r = s / n;
        while (l < r) {
            auto m = (l + r + 1) >> 1;
            long long tot = 0;
            for (auto x : a) {
                tot += min<long long>(m, x);
                if (tot >= m * n) break;
            }
            if (tot >= m * n) 
                l = m;
            else 
                r = m - 1;
        }
        return l;
    }
};
