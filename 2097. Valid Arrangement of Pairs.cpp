class Solution {
public:
    
    void dfs(unordered_map<int, vector<int>>& e, vector<int>& p, int x) {
        while (e[x].size()) {
            auto y = e[x].back();
            e[x].pop_back();
            dfs(e, p, y);
        }
        p.push_back(x);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> e;
        unordered_map<int, int> ind, oud;
        for (auto& pr : pairs) {
            e[pr[0]].push_back(pr[1]);
            ++ind[pr[1]];
            ++oud[pr[0]];
        }
        int start=-1;
        for (auto& pr : e) {
            int x = pr.first;
            if (ind[x]+1 == oud[x]) {
                start = x;
                break;
            }
        }
        if (start == -1) start = ind.begin()->first;
        vector<int> p;
        dfs(e, p, start);
        vector<vector<int>> ans;
        for (int i=p.size()-1; i-1>=0; --i) {
            ans.push_back({p[i], p[i-1]});
        }
        return ans;
    }
};