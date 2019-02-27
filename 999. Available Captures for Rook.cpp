class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int numRookCaptures(vector<vector<char>>& a) {
        int x, y;
        for (int i=0; i<8; ++i) 
            for (int j=0; j<8; ++j)
                if (a[i][j]=='R') {
                    x = i, y = j;
                    goto out;
                }
        out:
        
        int ans = 0;
        for (int dir=0; dir<4; ++dir) {
            int tx, ty;
            for (tx=x+dx[dir], ty=y+dy[dir]; 
                 tx>=0 && tx<8 && ty>=0 && ty<8 && a[tx][ty]=='.';
                 tx+=dx[dir], ty+=dy[dir]);
            if (tx>=0 && tx<8 && ty>=0 && ty<8 && a[tx][ty]=='p') 
                ++ans;
        }
        return ans;
    }
};