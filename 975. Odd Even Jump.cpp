class Solution {
public:
    
    bool go(const vector<vector<int>>& e, vector<vector<int>>& vis, int i, int p) {
        if (i+1==e.size()) return true;
        if (vis[i][p]!=-1) return vis[i][p];
        return vis[i][p] = (e[i][p]==-1 ? false : go(e, vis, e[i][p], 1^p));
    }
    
    int oddEvenJumps(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> e(n, vector<int>(2, -1));
        map<int, int> pos;
        for (int i=n-1; i>=0; --i) {
            auto it = pos.lower_bound(a[i]);
            if (it!=pos.end() && it->first==a[i])
                e[i][1] = e[i][0] = it->second;
            else {   
                if (it!=pos.end()) e[i][1] = it->second;
                if (it!=pos.begin()) e[i][0] = prev(it)->second;
            }
            pos[a[i]] = i;
        }
        vector<vector<int>> vis(n, vector<int>(2, -1));
        int ans = 0;
        for (int i=0; i<n; ++i) 
            if (go(e, vis, i, 1))
                ++ans;
        
        return ans;
    }
};