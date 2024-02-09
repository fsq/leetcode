class Solution {
public:
    int countCompleteSubarrays(vector<int>& a) {
        int ans = 0;
        vector<int> cnt(2001);
        int dst = unordered_set<int>(a.begin(), a.end()).size(), cur = 0;
        for (int i=0, j=0; i<a.size(); ++i) {
            while (j<a.size() && cur<dst) {
                if (++cnt[a[j]] == 1) ++cur;
                ++j;
            }
            if (cur < dst) break;
            ans += a.size() - j + 1;
            if (--cnt[a[i]]==0) --cur;
        }
        return ans;
    }
};