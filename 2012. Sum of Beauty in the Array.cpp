class Solution {
public:
    int sumOfBeauties(vector<int>& a) {
        int n = a.size();
        vector<int> r(n);
        r.back() = a.back();
        for (int i=n-2; i>0; --i)
            r[i] = min(r[i+1], a[i]);
        int l = a[0], ans = 0;
        for (int i=1; i+1<n; ++i) {
            if (l<a[i] && a[i]<r[i+1])
                ans += 2;
            else if (a[i-1]<a[i] && a[i]<a[i+1])
                ++ans;
            l = max(l, a[i]);
        }
        return ans;
    }
};