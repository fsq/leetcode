class Solution {
public:
    long long distinctNames(vector<string>& a) {
        vector<vector<int>> m(26, vector<int>(26)); // m[i][j]: can use i, start with j
        unordered_set<string> st(a.begin(), a.end());
        long long ans = 0;
        for (auto& s : a) {
            vector<pair<int,int>> add;
            for (char c='a'; c<='z'; ++c) {
                auto t = s;
                t[0] = c;
                if (!st.count(t)) {
                    ans += m[s[0]-'a'][c-'a'];
                    add.push_back({c-'a', s[0]-'a'});
                }
            }
            for (auto& p : add) ++m[p.first][p.second];
        }
        return ans * 2;
    }
};