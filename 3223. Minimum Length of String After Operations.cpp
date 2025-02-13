class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26);
        for (auto x : s) ++cnt[x-'a'];
        int ans = 0;
        for (auto x : cnt)
            if (x > 0)
                if (x & 1) {
                    ans += 1;
                } else {
                    ans += 2;
                }
        return ans;
    }
};