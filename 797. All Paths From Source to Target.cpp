class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& e, vector<int>& p, int x) {
        p.push_back(x);
        if (x+1 == e.size()) {
            ans.push_back(p);
        } else {
            for (auto y : e[x]) {
                dfs(e, p, y);
            }
        }
        p.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& e) {
        vector<int> p;
        dfs(e, p, 0);
        return ans;
    }
};