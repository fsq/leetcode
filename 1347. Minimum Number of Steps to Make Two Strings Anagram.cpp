class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26), b(26);
        for (auto x : s) ++a[x-'a'];
        for (auto x : t) ++b[x-'a'];
        int ans = 0;
        for (int i=0; i<26; ++i) ans += abs(a[i]-b[i]);
        return ans/2;
    }
};