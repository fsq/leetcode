class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        vector<int> vis(n);
        if (!a[start]) return true;
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int i=-1; i<=1; i+=2) {
                int y = x + a[x]*i;
                if (y>=0 && y<n && !vis[y]) {
                    if (!a[y]) return true;
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
        return false;
    }
};