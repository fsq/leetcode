class Solution {
public:
    int minimumScore(string s, string t) {
        int n = t.size();
        vector<int> l(n, -1), r(n, -1);
        for (int j=0, i=0; i<s.size() && j<n; ++i)
            if (s[i]==t[j]) {
                l[j] = i;
                ++j;
            }
        if (l.back() != -1) return 0;
        int ans = n;
        for (int j=n-1, i=s.size()-1; j>=0 && i>=0; --i)
            if (s[i]==t[j]) {
                r[j] = i;
                ans = j;
                --j;
            }
        for (int i=0, j=0; i<n; ++i) {
            if (l[i] == -1) break;
            while (j<n && r[j]<=l[i]) ++j;
            ans = min(ans, j-i-1);
        }
        return ans;
    }
};