class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rsv) {
        unordered_map<int, vector<int>> m;
        for (auto& st : rsv) {
            if (!m.count(st[0])) m[st[0]] = vector<int>(11, 1);
            m[st[0]][st[1]] = 0;
        }
        int ans = 0;
        for (const auto& [rn, row] : m) {
            bool c1 = row[2] && row[3] && row[4] && row[5];
            bool c2 = row[4] && row[5] && row[6] && row[7];
            bool c3 = row[6] && row[7] && row[8] && row[9];
            if (c1 || c3) {
                ans += c1;
                ans += c3;
            } else 
                ans += c2;
        }
        return ans + (n-m.size())*2;
    }
};