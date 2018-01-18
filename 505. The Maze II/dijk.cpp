class Solution {
public:
    // https://leetcode.com/problems/the-maze-ii/description/
    // dijkstra 
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = n==0 ? 0 : maze[0].size();
        
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, 
                            greater<pair<int,pair<int,int>>>> q;
        q.push({0, {start[0], start[1]}});
        
        while (true) {
            if (q.empty()) return -1;
            int dis = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            
            if (d[x][y]<dis) continue;
            d[x][y] = dis;
            
            if (x==destination[0] && y==destination[1]) return dis;
            
            for (int dir=0; dir<4; ++dir) {
                int nxtx=x, nxty=y, steps=0;
                for (int tx=x+dx[dir], ty=y+dy[dir]; 
                     tx>=0 && tx<n && ty>=0 && ty<m && maze[tx][ty]==0;
                     nxtx=tx, nxty=ty, tx+=dx[dir], ty+=dy[dir], ++steps);
                
                if (!(x==nxtx && y==nxty) && dis+steps<d[nxtx][nxty]) {
                    d[nxtx][nxty] = dis+steps;
                    q.push({dis+steps, {nxtx, nxty}});
                }
            }
        }
        return -1;
    }
};