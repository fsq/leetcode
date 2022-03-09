class Solution {
public:
    
    void bfs(vector<vector<int>>& e, vector<int>& d) {
        queue<int> q;
        q.push(0);
        d[0] = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto y : e[x])
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
        }
    }
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        int n = p.size();
        vector<int> d(n, -1);
        vector<vector<int>> e(n);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        bfs(e, d);
        int ans = 0;
        for (int i=1; i<n; ++i) {
            int recv = d[i] * 2;
            int num_send = (recv-1) / p[i];
            int last_send = num_send * p[i];
            int last_recv = last_send + d[i] * 2;
            ans = max(ans, last_recv + 1);
        }
        return ans;
    }
};