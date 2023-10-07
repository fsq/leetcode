class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int minimumTime(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if (a[0][1]>1 && a[1][0]>1) return -1;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> q;
        q.push({0, 0, 0});
        while (q.size()) {
            auto arr = q.top(); q.pop();
            int x = arr[1], y = arr[2], cost = arr[0];
            if (x==n-1 && y==m-1) return cost;
            for (int d=0; d<4; ++d) {
                int tx=x+dx[d], ty=y+dy[d];
                if (tx>=0 && tx<n && ty>=0 && ty<m && dis[tx][ty]==INT_MAX) {
                    if (a[tx][ty]<=cost+1) {
                        dis[tx][ty] = cost + 1;
                        q.push({cost+1, tx, ty});
                    } else {
                        // cost+2t+1 >= a[tx][ty]
                        int new_cost = ((a[tx][ty]-cost)&1) ? a[tx][ty] : a[tx][ty]+1;
                        dis[tx][ty] = new_cost;
                        q.push({new_cost, tx, ty});
                    }
                }
            }
        }
        return -1;
    }
};