class Solution {
public:
    int n;
    
    bool dfs(vector<int>& vis, vector<int>& s, int i) {
        if (i==s.size()) {
            return true;
        } else if (s[i] > 0) {
            return dfs(vis, s, i+1);
        } else {
            for (int x=n; x>0; --x)
                if (!vis[x] && (x==1 || i+x<s.size() && s[i+x]==0)) {
                    s[i] = s[i+(x==1 ? 0 : x)] = x;
                    vis[x] = true;
                    if (dfs(vis, s, i+1)) return true;
                    s[i] = s[i+(x==1 ? 0 : x)] = 0;
                    vis[x] = false;
                }
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n_) {
        n = n_;
        vector<int> s(n*2 - 1), vis(n+1);
        dfs(vis, s, 0);
        return s;
    }
};