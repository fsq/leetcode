class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> l(n+1, vector<int>(n+1));
        vector<vector<int>> e(n+1);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
            l[pr[0]][pr[1]] = l[pr[1]][pr[0]] = true;
        }
        int ans = INT_MAX;
        for (int x=1; x<=n; ++x) {
            for (int i=0; i<e[x].size(); ++i)
                for (int j=i+1; j<e[x].size(); ++j) {
                    int y = e[x][i], z = e[x][j];
                    if (l[y][z]) {
                        ans = min<int>(ans, e[x].size() + e[y].size() + e[z].size() - 6);
                    }
                }
        }
        if (ans==INT_MAX) ans = -1;
        return ans;
    }
};