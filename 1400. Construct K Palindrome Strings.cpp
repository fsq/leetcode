class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size()<k) return false;
        vector<int> cnt(128);
        for (auto x : s) ++cnt[x];
        int single = count_if(cnt.begin(), cnt.end(), [](int x) {
            return x & 1;
        });
        return single <= k;
    }
};