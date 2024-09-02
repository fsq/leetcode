class Solution {
public:
    const int M = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& mt) {
        int n = mt.size(), m = mt[0].size();
        vector<long long> u, v;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                u.push_back(mt[i][j]);
                v.push_back(mt[i][j]);
            }
        for (int i=1; i<n*m; ++i) {
            u[i] = (u[i] * u[i-1]) % M;
        }
        for (int i=n*m-2; i>0; --i) {
            v[i] = (v[i+1] * v[i]) % M;
        }
        auto ans = mt;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int id = i * m + j;
                long long x = 1;
                if (id > 0)
                    x = (x * u[id-1]) % M;
                if (id+1 < v.size())
                    x = (x * v[id+1]) % M;
                ans[i][j] = x;
            }
        return ans;
    }
};