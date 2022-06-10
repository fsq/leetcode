class Solution {
public:
    int minimumRefill(vector<int>& a, int ca, int cb) {
        int ans = 0, x=ca, y=cb;
        for (int l=0, r=a.size()-1;  l<=r; ++l, --r) 
            if (l == r) {
                if (max(x, y) < a[l]) ++ans;
            } else {
                if (x<a[l]) {
                    x = ca;
                    ++ans;
                }
                x -= a[l];
                if (y<a[r]) {
                    y = cb;
                    ++ans;
                }
                y -= a[r];
            }
        return ans;
    }
};