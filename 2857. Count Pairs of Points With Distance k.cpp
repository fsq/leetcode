class Solution {
public:
    int countPairs(vector<vector<int>>& a, int k) {
        unordered_map<int, unordered_map<int, int>> m;
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int x=a[i][0], y=a[i][1];
            for (int p=0; p<=k; ++p) {
                int u=p^x, v=(k-p)^y;
                if (m.count(u) && m[u].count(v))
                    ans += m[u][v];
            }
            ++m[x][y];
        }
        return ans;
    }
};