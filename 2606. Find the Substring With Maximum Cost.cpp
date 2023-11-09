class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> c(26);
        iota(c.begin(), c.end(), 1);
        for (int i=0; i<chars.size(); ++i)
            c[chars[i]-'a'] = vals[i];
        int ans = 0, f = 0;
        for (auto x : s) {
            f = max(f+c[x-'a'], c[x-'a']);
            ans = max(ans, f);
        }
        return ans;
    }
};