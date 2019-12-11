class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int n, m;
    
    int encode(const vector<vector<int>>& a) {
        int s = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j)
            s |= a[i][j] << (i*m + j);
        return s;
    }
    
    vector<vector<int>> decode(int s) {
        vector<vector<int>> a(n, vector<int>(m));
        for (int i=0; i<n*m; ++i)
            a[i/m][i%m] = (s>>i) & 1;
        return a;
    }
    
    int minFlips(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        
        int init = encode(a);        
        if (init == 0) return 0;
        
        unordered_set<int> vis;
        vis.insert(init);
        queue<int> q;
        q.push(init);
        
        for (int stp=1; q.size(); ++stp)
            for (int t=q.size(); t; --t) {
                vector<vector<int>> a = decode(q.front());
                q.pop();
                for (int i=0; i<n; ++i)
                    for (int j=0; j<m; ++j) {
                        auto b = a;
                        b[i][j] ^= 1;
                        for (int dir=0; dir<4; ++dir) {
                            int tx=i+dx[dir], ty=j+dy[dir];
                            if (tx>=0 && tx<n && ty>=0 && ty<m) 
                                b[tx][ty] ^= 1;
                        }
                        int stat = encode(b);
                        if (!vis.count(stat)) {
                            if (!stat) return stp;
                            vis.insert(stat);
                            q.push(stat);
                        }
                    }
                        
            }
        return -1;
        
    }
};