class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int mx = *max_element(a.begin(), a.end());
        int cnt = 0;
        long long ans = 0;
        for (int l=0, r=0; l<a.size(); ++l) {
            while (cnt<k && r<a.size()) {
                cnt += a[r++]==mx;
            }
            if (cnt==k) {
                ans += a.size() - r + 1;
            }
            if (a[l] == mx) --cnt;
        }
        return ans;

    }
};