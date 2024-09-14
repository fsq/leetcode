class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i=max(0, n-limit-limit); i<=min(limit, n); ++i) {
            int r = n - i;
            ans += min(r, limit) - max(0, r - limit) + 1;
        }
        return ans;
    }
};