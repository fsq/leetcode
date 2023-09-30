class Solution {
public:
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const int M = 1000000007;

    int squareFreeSubsets(vector<int>& nums) {
        vector<long long> f(1<<10);
        vector<int> cnt(31), msk(31);

        auto noSqr = [](int x) {
            for (auto d : {4, 9, 16, 25})
                if (x % d == 0)
                    return false;
            return true;
        };
        for (auto x : nums) 
            if (noSqr(x)) {
                ++cnt[x];
                int m = 0;
                for (int i=0; i<p.size(); ++i)
                    if (x % p[i] == 0)
                        m |= 1 << i;
                msk[x] = m;
            }

        int ans = 0;
        f[0] = 1;
        for (int x=1; x<=30; ++x)
            if (cnt[x]) {
                for (int m=1; m<(1<<10); ++m)
                    if (cnt[x] && (m&msk[x])==msk[x]) {
                        f[m] = (f[m] + f[m^msk[x]]*cnt[x])%M;
                    }
            }

        for (int m=1; m<(1<<10); ++m) {
            ans = (ans + f[m]) % M;
        }
        if (cnt[1]) {
            int b = 1;
            for (int i=0; i<cnt[1]; ++i) b = b*2%M;
            ans = (b + (long long)ans*b%M) % M;
            ans = (ans - 1 + M) % M;
        }
        return ans;
    }
};