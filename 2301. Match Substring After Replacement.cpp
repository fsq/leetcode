class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<int>> m(128, vector<int>(128));
        for (auto& mp : mappings) m[mp[0]][mp[1]] = 1;
        vector<int> f(sub.size()+1);
        f[0] = true;
        for (int i=1; i<=s.size(); ++i) {
            for (int j=min<int>(sub.size(), i); j>=1; --j) {
                f[j] = f[j-1] && (sub[j-1]==s[i-1] || m[sub[j-1]][s[i-1]]);
            }
            if (f[sub.size()]) return true;
        }
        return false;
    }
};