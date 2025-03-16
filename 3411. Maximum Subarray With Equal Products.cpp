#include <ranges>
class Solution {
public:
    int maxLength(vector<int>& a) {
        int ans = 2;
        for (int i: views::iota(0, (int)a.size())) {
            for (int j: views::iota(i+1, (int)a.size())) {
                bool ok = true;
                for (int k: views::iota(i, j)) {
                    if (gcd(a[k], a[j]) != 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};