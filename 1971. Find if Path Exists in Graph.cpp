class Solution {
public:
    vector<int> fa;
    int find(int x) {
        return fa[x]==x ? fa[x] : fa[x] = find(fa[x]);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        for (auto& e : edges) {
            int fx = find(e[0]), fy = find(e[1]);
            if (fx != fy) {
                fa[fx] = fy;
            }
        }
        return find(start) == find(end);
    }
};