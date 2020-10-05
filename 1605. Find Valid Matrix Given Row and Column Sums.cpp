class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
//         int n = r.size(), m = c.size();
//         vector<vector<int>> a(n, vector<int>(m));
        
//         set<pair<int,int>> rs, cs;
//         for (int i=0; i<r.size(); ++i) rs.insert({r[i], i});
//         for (int i=0; i<c.size(); ++i) cs.insert({c[i], i});
//         while (rs.size() && cs.size()) {
//             auto ri = *rs.begin(), ci = *cs.begin();
//             rs.erase(rs.begin());
//             cs.erase(cs.begin());
//             int num = min(ri.first, ci.first);
//             a[ri.second][ci.second] = num;
//             if (ri.first-num > 0) rs.insert({ri.first-num, ri.second});
//             if (ci.first-num > 0) cs.insert({ci.first-num, ci.second});
//         }
//         return a;
        int n = r.size();
        int m = c.size();
        vector<vector<int>> a(n,vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x =min( r[i] , c[j] );
                r[i] -= x;
                c[j] -= x;
                a[i][j] += x;
            }
        }
        return a;
    }
};