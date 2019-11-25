class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), tot = 0;
        vector<int> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]==1)
                    ++r[i], ++c[j], ++tot;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]==1 && r[i]==1 && c[j]==1)
                    --tot;
        return tot;
        
    }
};