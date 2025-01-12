class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> m;
        unordered_map<int, int> c;
        vector<int> ans;
        for (auto q: queries) {
            int x = q[0], cl = q[1];
            if (c.count(x) && --m[c[x]] == 0) m.erase(c[x]);
            c[x] = cl;
            ++m[cl];
            ans.push_back(m.size());
        }
        return ans;
    }
};