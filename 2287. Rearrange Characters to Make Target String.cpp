class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> a(26), b(26);
        for (auto x : s) ++a[x-'a'];
        for (auto x : target) ++b[x-'a'];
        int ans = INT_MAX;
        for (int i=0; i<26; ++i)
            if (b[i]) {
                ans = min(ans, a[i]/b[i]);
            }
        return ans;
    }
};