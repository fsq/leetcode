class Solution {
public:
    
    vector<int> dx={-1, 0, 1, 0};
    vector<int> dy={0, 1, 0, -1};
    
    bool hasValidPath(vector<vector<int>>& a) {
        if (a.size()==1 && a[0].size()==1) return true;
        auto vis = a;
        vector<vector<int>> p(7);
        p[1] = {0, 1, 0, 1};
        p[2] = {1, 0, 1, 0};
        p[3] = {0, 0, 1, 1};
        p[4] = {0, 1, 1, 0};
        p[5] = {1, 0, 0, 1};
        p[6] = {1, 1, 0, 0};
        queue<vector<int>> q;
        q.push({0, 0});
        vis[0][0] = -1;
        while (q.size()) {
            int x = q.front()[0], y = q.front()[1];
            q.pop();
            for (int d=0; d<4; ++d)
                if (p[a[x][y]][d]) {
                    int tx=x+dx[d], ty=y+dy[d];
                    if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && vis[tx][ty]!=-1 && p[a[tx][ty]][(d+2)%4]) {
                        q.push({tx, ty});
                        if (tx+1==a.size() && ty+1==a[0].size()) return true;
                        vis[tx][ty] = -1;
                    }
                }
            
        }
        return false;
    }
};