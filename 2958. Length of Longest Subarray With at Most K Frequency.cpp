class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        unordered_map<int, int> f;
        int lg = 0, ans = 0;
        for (int l=0,r=0; r<a.size(); ++r) {
            if (++f[a[r]] > k) {
                ++lg;
            }
            while (lg > 0) {
                if (--f[a[l++]]==k) --lg;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};