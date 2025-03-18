#include <ranges>

class Solution {
public:
    int subarraySum(vector<int>& a) {
        int ans = 0;
        for (int i: views::iota(0, (int)a.size())) {
            int cur = 0;
            for (int j: views::iota(max(0, i-a[i]), i+1)) {
                cur += a[j];
            }
            ans += cur;
        }
        return ans;
    }
};