class Solution {
public:

    int minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
        long long lcm = divisor1 * divisor2 / gcd(divisor1, divisor2);

        auto count = [=](long long x) -> bool {
            if (x-x/divisor1 < uniqueCnt1) return false;
            if (x-x/divisor2 < uniqueCnt2) return false;
            return x-x/lcm >= uniqueCnt1+uniqueCnt2;
        };

        long long l = 1, r = 2000000000;
        while (l < r) {
            int mid = (l+r) >> 1;
            if (!count(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};