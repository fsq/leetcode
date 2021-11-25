class Solution {
public:
    
    vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    bool checkMove(vector<vector<char>>& a, int x, int y, char color) {
        a[x][y] = color;
        char op = color=='W' ? 'B' : 'W';
        for (int d=0; d<8; ++d) {
            string line;
            for (int tx=x,ty=y; 
                 tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size();
                 tx+=dx[d], ty+=dy[d]) {
                line += a[tx][ty];
            }
            for (int i=1; i<line.size(); ++i) 
                if (line[i]==line[0] && i>1)
                    return true;
                else if (line[i]!=op)
                    break;
        }
        return false;
    }
};
