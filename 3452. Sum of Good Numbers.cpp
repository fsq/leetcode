#include <ranges>

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& a, int k) {
        auto v = std::views::enumerate(a) | views::filter([&] (const auto& t){
            auto [i, x] = t;
            return (i-k<0 || x>a[i-k]) && (i+k>=a.size() || x>a[i+k]);
        }) |
        views::transform([] (const auto& t){
            auto [i, x] = t;
            return x;
        });
        return accumulate(begin(v), end(v), 0);
    }
};