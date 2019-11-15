class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> e(n);
        vector<int> ind(n), ans(n);
        iota(ans.begin(), ans.end(), 0);
        
        for (auto& eg : richer) {
            e[eg[0]].push_back(eg[1]);
            ++ind[eg[1]];
        }
        queue<int> q;
        for (int i=0; i<n; ++i)
            if (!ind[i])
                q.push(i);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto y : e[x]) {
                if (a[ans[x]] < a[ans[y]])
                        ans[y] = ans[x];
                if (--ind[y] == 0) 
                    q.push(y);
            }
                
        }
        return ans;
    }
};