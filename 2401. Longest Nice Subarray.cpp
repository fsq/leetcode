class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        int ans = 0, m = 0;
        for (int l=0, r=0; r<a.size(); ++r) {
            while (l<r && (m&a[r])!=0) {
                m ^= a[l++];
            }
            m |= a[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};