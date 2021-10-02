class Solution {
public:
    long long wonderfulSubstrings(string s) {
        long long ans = 0, cur = 0;
        unordered_map<int, long long> cnt;
        ++cnt[0];
        for (auto c : s) {
            cur ^= 1 << (c-'a');
            ans += cnt[cur];
            for (int i=0; i<10; ++i) {
                int r = cur ^ (1<<i);
                ans += cnt[r];
            }
            ++cnt[cur];
        }
        return ans;
    }
};