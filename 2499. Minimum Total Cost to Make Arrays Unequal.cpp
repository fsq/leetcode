class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> f(n+1), b;
        int c = 0;
        long long ans = 0;
        for (int i=0; i<n; ++i)
            if (nums1[i] == nums2[i]) {
                ++f[nums1[i]];
                ++c;
                ans += i;
            } else 
                b.push_back(i);

        int need = 0, y = 0;
        for (int i=1; i<=n; ++i)
            if (2*f[i] > c) {
                need = 2*f[i] - c;
                y = i;
                break;
            }

        if (b.size() < need) return -1;
        for (int i=0; i<b.size() && need; ++i)
            if (nums1[b[i]] != y && nums2[b[i]] != y) {
                ans += b[i];
                --need;
            }
        return need ? -1 : ans;
    }
};