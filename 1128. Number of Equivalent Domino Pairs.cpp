class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& a : dominoes) {
            if (a[0] > a[1]) swap(a[0], a[1]);
            int s = a[0]*10 + a[1];
            ans += cnt[s]++;
        }
        return ans;
    }
};