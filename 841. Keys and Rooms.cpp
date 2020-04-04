class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rs) {
        int n = rs.size();
        if (n==1) return true;
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int open = 1;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto y : rs[x]) 
                if (!vis[y]) {
                    ++open;
                    vis[y] = true;
                    q.push(y);
                }
        }
        return open == n;
    }
};