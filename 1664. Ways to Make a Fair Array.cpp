class Solution {
public:
    int waysToMakeFair(vector<int>& a) {
        vector<int> s(2);
        for (int i=0; i<a.size(); ++i) s[i & 1] += a[i];
        int ans = 0;
        for (int x=0, y=0, i=0; i<a.size(); ++i) {
            int t0, t1;
            if (i & 1) {
                t0 = x + s[1]-y-a[i];
                t1 = y + s[0]-x;
            } else {
                t0 = x + s[1]-y;
                t1 = y + s[0]-x-a[i];
            }
            if (t0 == t1) ++ans;
            if (i & 1) 
                y += a[i];
            else 
                x += a[i];
        }
        return ans;
    }
};