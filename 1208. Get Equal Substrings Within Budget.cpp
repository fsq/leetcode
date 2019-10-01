class Solution {
public:
    int equalSubstring(string s, string t, int cost) {
        int n = s.size();
        vector<int> a(n);
        for (int i=0; i<n; ++i)
            a[i] = abs(s[i]-t[i]);
        int ans = 0;
        for (int l=0,r=0,x=0; r<n; ++r) {
            x += a[r];
            while (x > cost)
                x -= a[l++];
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};