class Solution {
public:

    int val(vector<int>& s) {
        int tot = 0;
        for (int i=0; i<31; ++i)
            if (s[i] > 0) 
                tot |= 1 << i;
        return tot;
    }

    int minimumSubarrayLength(vector<int>& a, int k) {
        int ans = INT_MAX;
        vector<int> s(31);
        for (int l=0,r=0; r<a.size(); ++r) {
            for (int j=0; j<31; ++j) s[j] += (a[r]>>j) & 1;
            while (val(s) >= k) {
                ans = min(ans, r-l+1);
                for (int j=0; j<31; ++j)
                    s[j] -= (a[l]>>j) & 1;
                ++l;
                if (ans == 1) return 1;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};