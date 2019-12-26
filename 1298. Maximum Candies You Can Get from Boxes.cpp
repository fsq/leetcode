class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        vector<int> vis(status.size());
        int open = 0, ans = 0;
        for (auto x : initialBoxes) {
            q.push(x);
            open += status[x];
            vis[x] = true;
        }
        
        while (open) {
            auto x = q.front(); q.pop();
            if (!status[x]) {
                q.push(x);
                continue;
            }
            --open;
            ans += candies[x];
            for (auto k : keys[x]) 
                if (!status[k]) {
                    status[k] = 1;
                    if (vis[k]) ++open;
                }
            
            for (auto b : containedBoxes[x]) {
                q.push(b);
                vis[b] = 1;
                open += status[b];
            }
            
        }
        
        return ans;
    }
};