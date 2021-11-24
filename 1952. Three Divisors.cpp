class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i=1; i*i<=n; ++i) {
            if (n % i == 0) {
                ++cnt;
                if (i != n/i) ++cnt;
                if (cnt > 3) return false;
            }
        }
        return cnt == 3;
    }
};