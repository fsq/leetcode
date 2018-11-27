class Solution {
public:
    
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    void merge(int x, int y) {
        if (find(x) != find(y))
            fa[fa[x]] = fa[y];
    }
    
    int removeStones(vector<vector<int>>& a) {
        int n = a.size();
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        
        unordered_map<int, vector<int>> rows, cols;
        for (int i=0; i<n; ++i) {
            rows[a[i][1]].push_back(i);
            cols[a[i][0]].push_back(i);
        }
        
        for (auto& row : rows) 
            for (int i=0; i+1<row.second.size(); ++i)
                merge(row.second[i], row.second[i+1]);
        for (auto& col : cols)
            for (int i=0; i+1<col.second.size(); ++i)
                merge(col.second[i], col.second[i+1]);
        
        int cc = 0;
        for (int i=0; i<n; ++i) cc += fa[i]==i;
        return n - cc;
    }
};