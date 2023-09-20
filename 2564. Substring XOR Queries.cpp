class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, pair<int, int>> m;
        for (int i=0; i<s.size(); ++i) 
            if (s[i] == '1') {
                long long x = 0;
                for (int j=0; j<32 && i+j<s.size(); ++j) {
                    x = (x<<1) + (s[i+j]-'0');
                    if (!m.count(x)) {
                        m[x] = {i, i+j};
                    }
                }
            } else if (!m.count(0)) {
                m[0] = {i, i};
            }
        vector<vector<int>> ans;
        for (auto &q : queries) {
            int x = q[0] ^ q[1];
            if (m.count(x)) {
                ans.push_back({m[x].first, m[x].second});
            } else {
                ans.push_back({-1, -1});
            }
        }
        return ans;
    }
};