class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rs) {
        if (rs.empty()) return n-1;
        
        rs.insert(rs.begin(), {1, 0}); // restrict building 1->0
        
        sort(rs.begin(), rs.end());
        int ans = 0;
        
        for (int i=1; i<rs.size(); ++i) {
            rs[i][1] = min(rs[i-1][1]+rs[i][0]-rs[i-1][0], rs[i][1]);
        }
        for (int i=rs.size()-2; i>=0; --i) {
            rs[i][1] = min(rs[i+1][1]+rs[i+1][0]-rs[i][0], rs[i][1]);
        }
        for (auto& r : rs) ans = max<long long>(ans, r[1]);
        
        // rs[i][0] + x == rs[i+1][0] + y
        for (int i=0; i+1<rs.size(); ++i) {
            int k = rs[i+1][0] - rs[i][0];
            int x2 = rs[i+1][1]-rs[i][1] + k;
            ans = max(ans, rs[i][1]+(x2 >> 1));
        }
        
        ans = max(ans, rs.back()[1] + n - rs.back()[0]);
        return ans;
    }
};