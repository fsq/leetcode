class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto dis = [=](int x, int y) {
            return abs(r0-x) + abs(c0-y);
        };
        vector<vector<int>> vis(R, vector<int>(C));
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        q.push({r0, c0});
        vis[r0][c0] = true;
        for (int x,y,d=0; !q.empty(); ) {
            tie(x, y) = q.front();
            q.pop();
            ans.push_back({x, y});
            d = dis(x, y);
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<R && ty>=0 && ty<C && !vis[tx][ty]) { 
                    vis[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
        return ans;
        
    }
};