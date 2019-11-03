class Solution {
public:
    
    bool vis[66000];
    
    bool dfs(int now, int n, vector<int>& ans) {
        vis[now] = true;
        ans.push_back(now);
        if (ans.size()==(1<<n)) {
            int d = ans.back() ^ ans.front();
            if ((d & (d-1)) == 0) return true;
        } else {
            for (int i=n-1; i>=0; --i) {
                int nxt = now ^ (1<<i);
                if (!vis[nxt] && dfs(nxt, n, ans)) return true;
            }
        }
        ans.pop_back();
        vis[now] = false;
        return false;
    }
    
    vector<int> circularPermutation(int n, int start) {
        memset(vis, 0, sizeof(vis));
        vector<int> ans;
        dfs(start, n, ans);
        return ans;
    }
};