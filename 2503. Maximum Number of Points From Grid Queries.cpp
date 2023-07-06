class Solution {
public:

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& queries) {
        vector<pair<int,int>> q;
        for (int i=0; i<queries.size(); ++i) q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        vector<int> ans(q.size());
        int n = a.size(), m = a[0].size();
        priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;
        pq.push({a[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(m));
        vis[0][0] = true;
        int acc = 0;
        for (auto& qr : q) {
            int bound = qr.first, i = qr.second;
            while (pq.size() && pq.top()[0]<bound) {
                auto x = pq.top(); pq.pop();
                vis[x[1]][x[2]] = true;
                ++acc;
                for (int dir=0; dir<4; ++dir) {
                    int tx=x[1]+dx[dir], ty=x[2]+dy[dir];
                    if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty]) {
                        vis[tx][ty] = true;
                        pq.push({a[tx][ty], tx, ty});
                    }
                }
            }
            ans[i] = acc;
        }
        return ans;
    }
};