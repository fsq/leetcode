class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int nearestExit(vector<vector<char>>& a, vector<int>& st) {
        queue<vector<int>> q;
        st.push_back(0);
        q.push(st);
        a[st[0]][st[1]] = 'x';
        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1], stp = q.front()[2];
            q.pop();
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && a[tx][ty]=='.') {
                    if (tx==0 || tx==a.size()-1 || ty==0 || ty==a[0].size()-1)
                        return stp+1;
                    q.push({tx, ty, stp+1});
                    a[tx][ty] = 'x';
                }
            }
        }
        return -1;
    }
};