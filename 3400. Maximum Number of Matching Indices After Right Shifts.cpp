#include <ranges>
class Solution {
public:
    int maximumMatchingIndices(vector<int>& a, vector<int>& b) {
        int ans = 0;
        for (auto shift: views::iota(0, (int)a.size())) {
            int cnt = 0;
            for (int i: views::iota(0, (int)a.size())) {
                if (a[i] == b[(i+shift) % a.size()]) {
                    cnt += 1;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};