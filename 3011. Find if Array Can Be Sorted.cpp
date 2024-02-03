class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int mx = -1;
        for (int l=0, r=0; l<a.size();) {
            int cur_min = INT_MAX, cur_max = INT_MIN;
            for (r=l; r<a.size() && __builtin_popcount(a[r])==__builtin_popcount(a[l]);) {
                cur_min = min(cur_min, a[r]);
                cur_max = max(cur_max, a[r]);
                ++r;
            }
            if (cur_min < mx) return false;
            mx = cur_max;
            l = r;
        }
        return true;
    }
};