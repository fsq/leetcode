class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int,long long>> a;
        long long ans = 0;
        for (auto x: nums) {
            ++ans;
            while (a.size() && x>a.back().first) a.pop_back();
            if (a.size() && a.back().first==x) {
                ans += a.back().second;
                ++a.back().second;
            } else {
                a.push_back({x, 1});
            }
        }
        return ans;
    }
};