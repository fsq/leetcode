class Solution {
public:
    bool isPrintable(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> bound(61, vector<int>{n, 0, m, 0});
            
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int c = a[i][j];
                bound[c][0] = min(bound[c][0], i);
                bound[c][1] = max(bound[c][1], i);
                bound[c][2] = min(bound[c][2], j);
                bound[c][3] = max(bound[c][3], j);
            }
        vector<vector<vector<int>>> cover(n, vector<vector<int>>(m));
        for (int c=1; c<=60; ++c) {
            for (int x=bound[c][0]; x<=bound[c][1]; ++x)
                for (int y=bound[c][2]; y<=bound[c][3]; ++y)
                    cover[x][y].push_back(c);
        }
        
        vector<vector<int>> e(61);
        vector<int> ind(61);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                for (auto c : cover[i][j])
                    if (c != a[i][j]) {
                        e[a[i][j]].push_back(c);
                        ++ind[c];
                    }
        queue<int> q;
        for (int i=1; i<=60; ++i)
            if (!ind[i])
                q.push(i);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto y : e[x])
                if (--ind[y] == 0)
                    q.push(y);
        }
        return *max_element(ind.begin(), ind.end()) == 0;
    }
};