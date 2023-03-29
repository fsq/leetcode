class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        vector<int> cnt(26);
        for (auto c : s) {
            if (cnt[c-'a']) {
                ++ans;
                fill(cnt.begin(), cnt.end(), 0);
            }
            ++cnt[c-'a'];
        }
        return ans;
    }
};