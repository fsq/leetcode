class Solution {
public:
    int countTriplets(vector<int>& a) {
        unordered_map<int, int> cnt, sum;
        auto s = a;
        for (int i=1; i<s.size(); ++i) s[i] ^= s[i-1];
        ++cnt[0];
        sum[0] = 0;
        int ans = 0;
        for (int k=1; k<s.size(); ++k) {
            if (k-2>=0) {
                ++cnt[s[k-2]];
                sum[s[k-2]] += k - 1;
            }
            if (cnt.count(s[k])) {
                ans += k*cnt[s[k]] - sum[s[k]];
            }
        }
        return ans;
    }
};