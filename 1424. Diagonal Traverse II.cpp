class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& m) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<int> ans;
        while (!q.empty()) 
            for (int t=q.size(), i=0; i<t; ++i) {
                auto p = q.front(); q.pop();
                ans.push_back(m[p.first][p.second]);
                if (p.second==0 && p.first+1 < m.size()) {
                    q.push({p.first+1, p.second});
                }
                if (p.second+1 < m[p.first].size()) {
                    q.push({p.first, p.second+1});
                }
            }
        return ans;
    }
};