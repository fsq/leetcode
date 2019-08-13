class Solution {
public:
    int maxRepOpt1(string s) {
        int n = s.size();
        vector<int> cnt(129), f(n);
        for (auto c : s) ++cnt[c];
        f[0] = 1;
        int ans = 0;
        for (int i=1; i<n; ++i) {
            f[i] = (s[i]==s[i-1] ? f[i-1] : 0) + 1;
            ans = max(ans, f[i]);
            if (i-f[i]==0 && cnt[s[i]]>f[i] || 
                i-f[i]>0 && s[i-f[i]-1]==s[i] && f[i]+f[i-f[i]-1]<cnt[s[i]])
                ans = max(ans, f[i]+1+(i-f[i]==0 ? 0 : f[i-f[i]-1]));
            if (s[i]!=s[i-1] && cnt[s[i-1]]>f[i-1])
                ans = max(ans, f[i-1]+1);
        }
        return ans;
    }
};