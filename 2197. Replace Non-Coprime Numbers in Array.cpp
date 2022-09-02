class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (auto x : nums) {
            while (ans.size()) {
                auto g = gcd(ans.back(), x);
                if (g == 1) break;
                x = x / g * ans.back();
                ans.pop_back();
            }
            ans.push_back(x);
        }
        return ans;
    }
};