class Solution {
public:
    long long ans = 0;

    void dfs(const string& s, vector<vector<int>>& e, int x, int p, unordered_map<int, int>& m) {
        if (x != 0) {
            if (m.contains(p))
                ans += m[p];
            for (int i=0; i<26; ++i) 
                if (m.contains(p ^ (1<<i))) {
                    ans += m[p ^ (1<<i)];
                }
        }
        ++m[p];
        for (auto y : e[x]) {
            dfs(s, e, y, p^(1 << (s[y]-'a')), m);
        }
    }

    long long countPalindromePaths(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> e(n);
        for (int i=1; i<n; ++i) {
            e[p[i]].push_back(i);
        }
        unordered_map<int, int> m;
        dfs(s, e, 0, 0, m);
        return ans;
    }
};