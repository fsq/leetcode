class Solution {
public:

    vector<int> topo(vector<vector<int>>& a, int k) {
        vector<int> ind(k+1);
        vector<vector<int>> e(k+1);
        for (auto& pr : a) {
            e[pr[0]].push_back(pr[1]);
            ++ind[pr[1]];
        } 
        vector<int> ans;
        queue<int> q;
        for (int i=1; i<=k; ++i)
            if (ind[i]==0)
                q.push(i);
        while (q.size()) {
            auto x = q.front(); q.pop();
            ans.push_back(x);
            for (auto y : e[x])
                if (--ind[y]==0)
                    q.push(y);
        }
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        auto rs = topo(rc, k);
        if (rs.size() < k) return {};
        auto cs = topo(cc, k);
        if (cs.size() < k) return {};

        vector<pair<int,int>> pos(k+1);
        for (int i=0; i<k; ++i) {
            pos[rs[i]].first = i;
            pos[cs[i]].second = i;
        }
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i=1; i<=k; ++i)
            ans[pos[i].first][pos[i].second] = i;
        return ans;
    }
};