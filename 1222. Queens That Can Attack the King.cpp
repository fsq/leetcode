class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<vector<int>> ans, p(8, vector<int>(8, -1));
        for (int i=0; i<queens.size(); ++i)
            p[queens[i][0]][queens[i][1]] = i;
        for (int dir=0; dir<8; ++dir) {
            for (int x=k[0], y=k[1]; x>=0 && x<8 && y>=0 && y<8; x+=dx[dir], y+=dy[dir])
                if (p[x][y] >= 0) {
                    ans.push_back({x, y});
                    break;
                }
        }
        return ans;
    }
};