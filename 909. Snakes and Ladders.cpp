class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> a{0};
        for (int i=n-1,j=0,d=1; i>=0; ) {
            a.push_back(board[i][j]);
            j += d;
            if (j==n || j==-1) {
                j -= d;
                --i;
                d = -d;
            }
        }
        
        vector<int> f(a.size(), INT_MAX);
        f[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i=x+1; i<=x+6 && i<=n*n; ++i) {
                int dst = a[i]==-1 ? i : a[i];
                if (f[dst] == INT_MAX) {
                    q.push(dst);
                    f[dst] = f[x] + 1;
                    if (dst == n*n) return f[dst];
                }
            }
        }
        return -1;
    }
};