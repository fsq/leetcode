class Solution {
public:
    int videoStitching(vector<vector<int>>& a, int t) {
        sort(a.begin(), a.end());
        int r = 0, ans = 0;
        for (int i=0; r<t && i<a.size(); ) {
            int mxr = -1;
            while (i<a.size() && a[i][0]<=r) {
                mxr = max(mxr, a[i][1]);
                ++i;
            }
            if (mxr == -1) return -1;
            ++ans;
            r = mxr;
        }
        if (r < t) return -1;
        return ans;
    }
};