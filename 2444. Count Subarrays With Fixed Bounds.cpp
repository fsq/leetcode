class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        long long ans = 0;
        for (int l=0,r; l<a.size(); )
            if (a[l]>=minK and a[l]<=maxK) {
                queue<int> x, y;
                for (r=l; r<a.size() && a[r]>=minK && a[r]<=maxK; ++r) {
                    if (a[r]==minK) x.push(r);
                    if (a[r]==maxK) y.push(r);
                }
                for (int i=l; i<r && x.size() && y.size(); ++i) {
                    if (x.front()<i) x.pop();
                    if (y.front()<i) y.pop();
                    if (x.size() && y.size()) {
                        ans += r - (max(x.front(), y.front()));
                    }
                }
                l = r;
            } else {
                ++l;
            }
        return ans;
    }
};