class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& a, vector<int>& pricing, vector<int>& start, int k) {
        set<vector<int>> st;
        queue<vector<int>> q;
        vector<vector<int>> vis(a.size(), vector<int>(a[0].size()));
        vis[start[0]][start[1]] = true;
        start.push_back(0);
        q.push(start);
        if (a[start[0]][start[1]]>=pricing[0] && a[start[0]][start[1]]<=pricing[1]) {
            st.insert({0, a[start[0]][start[1]], start[0], start[1]});
        }
        while (q.size()) {
            auto p = q.front(); q.pop();
            int x=p[0], y=p[1], dis=p[2];
            for (auto dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && a[tx][ty]!=0 && !vis[tx][ty]) {
                    vis[tx][ty] = true;
                    if (a[tx][ty] >= pricing[0] && a[tx][ty] <= pricing[1]) {
                        vector<int> newp = {dis+1, a[tx][ty], tx, ty};
                        st.insert(newp);
                        if (st.size()>k) st.erase(prev(st.end()));
                    }
                    q.push({tx, ty, dis+1});
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& p : st)
            ans.push_back({p[2], p[3]});
        return ans;
    }
};