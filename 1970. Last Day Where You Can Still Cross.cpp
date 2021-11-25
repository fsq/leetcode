class Solution {
public:
    vector<int> fa;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        fa.resize(row * col);
        iota(fa.begin(), fa.end(), 0);
        vector<vector<int>> a(row, vector<int>(col)), bottom=a;
        for (int i=0; i<col; ++i)
            bottom[row-1][i] = true;
        for (int i=cells.size()-1; i>=0; --i) {
            int x = cells[i][0]-1, y = cells[i][1]-1;
            a[x][y] = 1;
            for (int d=0; d<4; ++d) {
                int tx=x+dx[d], ty=y+dy[d];
                if (tx>=0 && tx<row && ty>=0 && ty<col && a[tx][ty]==1) {
                    int fx = find(x*col+y), fy = find(tx*col+ty);
                    if (fx > fy) swap(fx, fy);
                    if (fx != fy) {
                        fa[fy] = fx;
                        if (bottom[fy/col][fy%col]) {
                            if (fx<col) return i;
                            bottom[fx/col][fx%col] = true;
                        } else if (bottom[fx/col][fx%col]) {
                            if (fy<col) return i;
                            bottom[fy/col][fy%col] = true;
                        }
                    }
                }
            }
        }
        return 0;
    }
};