class Solution {
public:

    vector<int> dx = {1, 0};
    vector<int> dy = {0, 1};

    bool dfs(vector<vector<int>>& a, int x, int y) {
        a[x][y] = 0;
        for (int d=0; d<2; ++d) {
            int tx=x+dx[d], ty=y+dy[d];
            if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && a[tx][ty]==1) {
                if (tx+1==a.size() && ty+1==a[0].size()) return true;
                if (dfs(a, tx, ty)) return true;
            }
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>> a) {
        if (a.size()==1 && a[0].size()==1) return false;
        if (!dfs(a, 0, 0)) return true;
        return !dfs(a, 0, 0);
    }
};