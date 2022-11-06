class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& a, int carpetLen) {
        sort(a.begin(), a.end());
        int ans = 0;
        int r = 0, len = 0;
        for (int l=0; l<a.size(); ++l) {
            while (r<a.size() && a[r][1]<=a[l][0]+carpetLen-1) {
                len += a[r][1] - a[r][0] + 1;
                ++r;
            }
            int cur = len + (r<a.size() ? max(0, a[l][0]+carpetLen - a[r][0]) : 0);
            ans = max(ans, cur);
            len -= a[l][1] - a[l][0] + 1;
        }
        return ans;
    }
};