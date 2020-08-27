class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> vis(n+1);
        for (int i=0; i+1<rounds.size(); ++i) {
            int x = rounds[i], y = rounds[i+1];
            while (x != y) {
                ++vis[x++];
                if (x==n+1) x = 1;
            }
        }
        ++vis[rounds.back()];
        vector<int> ans = {1};
        for (int i=2; i<=n; ++i)
            if (vis[i] > vis[ans.front()]) {
                ans = {i};
            } else if (vis[i] == vis[ans.front()]) {
                ans.push_back(i);
            }
        return ans;
    }
};