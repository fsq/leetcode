class Solution {
public:
    
    int n, m;
    vector<vector<int>> e;
    vector<int> ind, fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    int encode(int x, int y) {
        return x * m + y;
    }
    
    void merge(int x, int y) {
        int fx=find(x), fy=find(y);
        if (fx != fy) {
            fa[fx] = fy;
        }
    }
    
    void link(int x, int y) {
        ++ind[find(y)];
        e[find(x)].push_back(find(y));
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        e.resize(n * m);
        fa.resize(n * m);
        ind.resize(n * m);
        iota(fa.begin(), fa.end(), 0);
        for (int i=0; i<n; ++i) {
            unordered_map<int, vector<int>> b;
            for (int j=0; j<m; ++j) b[a[i][j]].push_back(j);
            for (auto& pr : b)
                for (int j=1; j<pr.second.size(); ++j)
                    merge(encode(i, pr.second[0]), encode(i, pr.second[j]));
        }

        for (int i=0; i<m; ++i) {
            unordered_map<int, vector<int>> b;
            for (int j=0; j<n; ++j) b[a[j][i]].push_back(j);
            for (auto& pr : b)
                for (int j=1; j<pr.second.size(); ++j)
                    merge(encode(pr.second[0], i), encode(pr.second[j], i));
        }
        
        for (int i=0; i<n; ++i) {
            map<int, int> t;
            for (int j=0; j<m; ++j) t[a[i][j]] = j;
            for (auto it=t.begin(); next(it)!=t.end(); ++it) {
                int x = it->second, y = next(it)->second;
                link(encode(i, x), encode(i, y));
            }
        }
        
        for (int i=0; i<m; ++i) {
            map<int, int> t;
            for (int j=0; j<n; ++j) t[a[j][i]] = j;
            for (auto it=t.begin(); next(it)!=t.end(); ++it) {
                int x = it->second, y = next(it)->second;
                link(encode(x, i), encode(y, i));
            }
        }

        queue<int> q;
        ind.resize(n*m);
        vector<int> h(n * m, 1);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int x = encode(i, j);
                if (find(x)==x && ind[x]==0) {
                    q.push(x);
                }
            }
        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto y: e[x]) {
                h[y] = max(h[y], h[x] + 1);
                if (--ind[y] == 0)
                    q.push(y);
            }
        }
        for (int i=0; i<h.size(); ++i)
            if (h[i] == 0)
                h[i] = h[find(i)];
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                a[i][j] = h[find(encode(i, j))];
        return a;
    }
};