class Solution {
public:
    long long beautifulSubarrays(vector<int>& a) {
        int cur = 0;
        long long ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (auto x : a) {
            cur ^= x;
            ans += m[cur];
            ++m[cur];
        }
        return ans;
    }
};