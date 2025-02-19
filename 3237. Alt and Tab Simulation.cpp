class Solution {
public:
    vector<int> simulationResult(vector<int>& a, vector<int>& q) {
        int n = a.size();
        vector<int> vis(n+1);
        vector<int> ans;
        for (auto it=q.rbegin(); it!=q.rend(); ++it) {
            int x = *it;
            if (!vis[x]) {
                vis[x] = true;
                ans.push_back(x);
            }
        }
        for (auto x : a)
            if (!vis[x])
                ans.push_back(x);
        return ans;
    }
};