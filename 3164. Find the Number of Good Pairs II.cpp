class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int m1 = ranges::max(nums1);
        int m2 = ranges::max(nums2);
        vector<long long> c1(m1+1), c2(m2+1);
        for (auto x : nums1) ++c1[x];
        for (auto x : nums2) ++c2[x];
        for (int i=1; i<=m2; ++i)
            if (c2[i]) {
                for (long long x=i*k; x<=m1; x+=i*k)
                    ans += c2[i] * c1[x];
            }
        return ans;
    }
};