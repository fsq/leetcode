class NeighborSum {
public:
    vector<vector<int>> a;
    unordered_map<int, pair<int, int>> p;


    NeighborSum(vector<vector<int>>& grid) {
        a = grid;
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j) {
                p[a[i][j]] = {i, j};
            }
    }
    
    vector<int> ax = {-1, 0, 1, 0};
    vector<int> ay = {0, 1, 0, -1};
    int adjacentSum(int value) {
        auto [x, y] = p[value];
        int ans = 0;
        for (int d=0; d<4; ++d) {
            int tx=x+ax[d], ty=y+ay[d];
            if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size()) {
                ans += a[tx][ty];
            }
        }
        return ans;
    }

    vector<int> dx = {-1, -1, 1, 1};
    vector<int> dy = {-1, 1, -1, 1};
    int diagonalSum(int value) {
        auto [x, y] = p[value];
        int ans = 0;
        for (int d=0; d<4; ++d) {
            int tx=x+dx[d], ty=y+dy[d];
            if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size()) {
                ans += a[tx][ty];
            }
        }
        return ans; 
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */