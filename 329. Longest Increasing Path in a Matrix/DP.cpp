class Solution {
public:
    
    // https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
    // O(nm) time&space DP
    // the graph is a DAG, meeting topological structure
    
    vector<vector<int>> f;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int n, m;
    
    int dp(const vector<vector<int>>& matrix, int x, int y) {
        if (f[x][y]!=0)
            return f[x][y];
        
        f[x][y] = 1;
        for (int dir=0; dir<4; ++dir) {
            int tx = x + dx[dir];
            int ty = y + dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m && matrix[tx][ty]>matrix[x][y]) 
                f[x][y] = max(f[x][y], 1 + dp(matrix, tx, ty));
        }
        
        return f[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = n==0 ? 0 : matrix[0].size();
        f = vector<vector<int>>(n, vector<int>(m, 0));
        
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ans = max(ans, dp(matrix, i, j));
        
        return ans;
    }
};