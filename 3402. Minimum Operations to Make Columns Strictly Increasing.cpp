#include <ranges>

class Solution {
public:
    int minimumOperations(vector<vector<int>>& a) {
        int ans = 0;
        for (int j: std::views::iota(0, (int)a[0].size())) {
            int pre = -1;
            for (int i: std::views::iota(0, (int)a.size())) {
                if (a[i][j] <= pre) {
                    ans += pre+1 - a[i][j];
                    pre = pre + 1;
                } else {
                    pre = a[i][j];
                }
            }
        }
        return ans;
    }
};