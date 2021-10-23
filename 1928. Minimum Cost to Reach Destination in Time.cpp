class Solution {
public:
    
    int f[1001][1001]; // f[i][j] = minimum fee to reach city i at time j
    int t[1001][1001]; // t[i][j] = time from city i to city j
    const int INF = 0x3f3f3f3f;
    
    int dp(vector<unordered_set<int>>& e,  vector<int>& fee, int i, int maxTime) {
        int& ans = f[i][maxTime];
        if (ans != -1) return ans;
        ans = INF;
        for (auto j : e[i]) 
            if (t[j][i] <= maxTime) {
                int fj = dp(e, fee, j, maxTime-t[j][i]);
                if (fj != INF) {
                    ans = min(ans, fj + fee[i]);
                }
            }
        return ans;
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        memset(f, -1, sizeof(f));
        memset(t, 0x3f, sizeof(t));
        vector<unordered_set<int>> e(fee.size());
        for (auto& p : edges) {
            t[p[0]][p[1]] = min(t[p[0]][p[1]], p[2]);
            t[p[1]][p[0]] = t[p[0]][p[1]];
            e[p[0]].insert(p[1]);
            e[p[1]].insert(p[0]);
        }
        for (int i=0; i<=maxTime; ++i)
            f[0][i] = fee[0];
        int ans = dp(e, fee, fee.size()-1, maxTime);
        return ans == INF ? -1 : ans;
    }
};