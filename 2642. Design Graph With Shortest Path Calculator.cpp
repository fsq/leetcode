class Graph {
public:
    vector<vector<int>> f;
    int n;
    const int INF = 0x3f3f3f3f;

    Graph(int _n, vector<vector<int>>& edges) {
        n = _n;
        f = vector<vector<int>>(n, vector<int>(n, INF));
        for (auto& e : edges) f[e[0]][e[1]] = e[2];
        for (int k=0; k<n; ++k) {
            f[k][k] = 0;
            for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i != j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    
    void addEdge(vector<int> e) {
        int x=e[0], y=e[1], d=e[2];
        if (f[x][y] < d) return;
        f[x][y] = d;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i != j)
                    f[i][j] = min(f[i][j], f[i][x]+d+f[y][j]);
    }
    
    int shortestPath(int node1, int node2) {
        return f[node1][node2]==INF ? -1 : f[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */