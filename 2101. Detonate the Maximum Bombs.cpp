class Solution {
public:
    
    bool range(vector<vector<int>>& a, int x, int y) {
        long long d = (long long)(a[x][0]-a[y][0])*(a[x][0]-a[y][0]) + 
                      (long long)(a[x][1]-a[y][1])*(a[x][1]-a[y][1]);
        return (long long)a[x][2]*a[x][2] >= d;
    }
    
    int maximumDetonation(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> e(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i!=j) {
                    if (range(a, i, j)) e[i].push_back(j);
                    if (range(a, j, i)) e[j].push_back(i);
                }
        vector<bool> vis(n);
        int ans = 0;
        for (int i=0; i<n; ++i) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            int cnt = 1;
            while (q.size()) {
                int x = q.front(); q.pop();
                for (auto y : e[x])
                    if (!vis[y]) {
                        q.push(y);
                        vis[y] = true;
                        ++cnt;
                    }
            }
            fill(vis.begin(), vis.end(), false);
            ans = max(ans, cnt);
        }
        return ans;
    }
};