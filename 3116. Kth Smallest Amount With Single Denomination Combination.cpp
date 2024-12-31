class Solution {
public:

    long long lcm(long long x, long long y) {
        long long g = gcd(x, y);
        return x / g * y;
    }

    long long count(vector<int>& a, long long x) {
        long long cnt = 0;
        vector<vector<long long>> s(a.size()+1);
        for (int i=0; i<a.size(); ++i) {
            cnt += x / a[i];
            for (int j=s.size()-1; j>=1; --j)
                for (auto y: s[j]) {
                    auto l = lcm(y, a[i]);
                    cnt += (j%2==1 ? -1 : 1) * (x / l);
                    s[j+1].push_back(l);
                }
            s[1].push_back(a[i]);
        }
        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 50000000000;
        while (l < r) {
            long long m = (l+r) >> 1;
            if (count(coins, m) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};