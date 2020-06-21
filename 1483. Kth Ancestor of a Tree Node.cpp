class TreeAncestor {
public:
    vector<vector<int>> f;

    TreeAncestor(int n, vector<int>& parent) {
        f = vector<vector<int>>(n+1, vector<int>(17, -1));
        for (int i=0; i<n; ++i) f[i][0] = parent[i];
        for (int j=1; j<=16; ++j)
            for (int i=1; i<n; ++i)
                if (f[i][j-1]!=-1)
                    f[i][j] = f[f[i][j-1]][j-1];
    }
    
    int getKthAncestor(int x, int k) {
        for (int j=16; x!=-1 && k; --j)
            if (k >= (1<<j)) {
                x = f[x][j];
                k -= 1 << j;
            }
        return x;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */