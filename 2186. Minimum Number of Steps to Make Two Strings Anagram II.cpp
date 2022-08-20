class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26), b(26);
        for (auto c : s) ++a[c-'a'];
        for (auto c : t) ++b[c-'a'];
        int ans = 0;
        for (int i=0; i<26; ++i) {
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
};