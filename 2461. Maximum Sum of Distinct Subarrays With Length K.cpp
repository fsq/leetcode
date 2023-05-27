class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        long long ans=0, s=0;
        unordered_map<int, int> cnt;
        for (int i=0; i+1<k; ++i) {
            ++cnt[a[i]];
            s += a[i];
        }
        for (int r=k-1; r<a.size(); ++r) {
            if (r-k>=0) {
                if (--cnt[a[r-k]]==0) cnt.erase(a[r-k]);
                s -= a[r-k];
            }
            ++cnt[a[r]];
            s += a[r];
            if (cnt.size()==k) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};