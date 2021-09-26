class Solution {
public:
    int n, m;
    
    void move(int& x, int& y, int l) {
        if (x == l) {
            if (y == l) {
                ++x;
            } else {
                --y;
            }
        } else if (x == n-1-l) {
            if (y == m-l-1) {
                --x;
            } else 
                ++y;
        } else if (y == l) 
            ++x;
        else 
            --x;
    }
        
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) {
        vector<vector<int>> b = a;
        n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int l = min(min(i, n-i-1), min(j, m-j-1));
                int sz = n*2+m*2 - l*8 - 4;
                int x=i, y=j;
                for (int stp=0; stp<k%sz; ++stp)
                    move(x, y, l);
                b[x][y] = a[i][j];
            }
        return b;
    }
};