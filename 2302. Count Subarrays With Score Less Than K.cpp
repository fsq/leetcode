class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        long long ans = 0, cur = 0;
        for (int r=0, l=0; l<a.size(); ++l) {
            while (r<a.size() && (cur+a[r])*(r-l+1)<k) {
                cur += a[r];
                ++r;
            }
            ans += r - l;
            cur -= a[l];
        }
        return ans;
    }
};