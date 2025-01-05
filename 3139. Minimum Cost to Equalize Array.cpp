class Solution {
public:
    const int M = 1000000007;

    int minCostToEqualizeArray(vector<int>& a, int c1, int c2) {
        sort(a.begin(), a.end());
        long long tot = 0, mx = 0, mn = LLONG_MAX, n = a.size();
        for (auto x : a) {
            tot += x;
            mx = max<long long>(mx, x);
            mn = min<long long>(mn, x);
        }
        // always use op1
        if (2*c1 <= c2) {
            return (mx*n - tot) % M * c1 % M;
        }
        long long ret = LLONG_MAX;
        for (long long target=mx; target<=2*mx; ++target) {
            auto smallest = target - mn;
            auto required = target*n - tot;
            long long pair = 0;
            if (target - mn > required - (target - mn)) { // not enough pairs for min element
                pair = required - (target - mn);
            } else {
                pair = required / 2;
            }
            auto op1 = required - pair * 2;
            ret = min(ret, op1*c1 + pair*c2);
        }
        return ret % M;
    }
};