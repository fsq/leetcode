class Solution {
public:
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int l = lower - a[i], r = upper - a[i];
            int li = lower_bound(a.begin()+i+1, a.end(), l) - a.begin();
            int ri = upper_bound(a.begin()+i+1, a.end(), r) - a.begin() - 1;
            ans += (ri - li + 1);
        }
        return ans;
    }
};