class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& pr : adjacentPairs) {
            adj[pr[0]].push_back(pr[1]);
            adj[pr[1]].push_back(pr[0]);
        }
        vector<int> ans;
        for (auto& pr :adj)
            if (pr.second.size()==1) {
                ans.push_back(pr.first);
                break;
            }
        for (int i=1; i<adj.size(); ++i) {
            int x = ans.back();
            if (adj[x].size()==1) {
                ans.push_back(adj[x][0]);
            } else {
                for (auto y : adj[x])
                    if (y != ans[ans.size()-2]) {
                        ans.push_back(y);
                        break;
                    }
            }
        }
        return ans;
    }
};