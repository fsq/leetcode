class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if (n==1 && m==1) return 1;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 1;

        vector<set<int>> cf(m), rf(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                rf[i].insert(j);
                cf[j].insert(i);
            }

        queue<vector<int>> q;
        q.push({0, 0});

        while (q.size()) {
            int x = q.front()[0], y = q.front()[1];
            q.pop();
            for (auto it=rf[x].lower_bound(y); it!=rf[x].end()&&*it<=y+a[x][y];) {
                int j = *it;
                if (dis[x][y]+1 < dis[x][j]) {
                    dis[x][j] = dis[x][y] + 1;
                    if (x==n-1 && j==m-1) return dis[x][j];
                    q.push({x, j});
                }
                cf[j].erase(x);
                it = rf[x].erase(it);
            }

            for (auto it=cf[y].lower_bound(x); it!=cf[y].end()&&*it<=x+a[x][y]; ) {
                int i = *it;
                if (dis[x][y]+1 < dis[i][y]) {
                    dis[i][y] = dis[x][y] + 1;
                    if (i==n-1 && y==m-1) return dis[i][y];
                    q.push({i, y});
                }
                rf[i].erase(y);
                it = cf[y].erase(it);
            }
        }
        return -1;
    }
};