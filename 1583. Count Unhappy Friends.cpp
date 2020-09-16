class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<int> p(n);
        for (auto& pr : pairs) {
            p[pr[0]] = pr[1];
            p[pr[1]] = pr[0];            
        }
        
        vector<vector<int>> s(n, vector<int>(n));
        for (int i=0; i<n; ++i)
            for (int j=0; j<n-1; ++j)
                s[i][pref[i][j]] = n - j;
        
        int ans = 0;
        for (int x=0; x<n; ++x) {
            int y = p[x];
            for (int u : pref[x])
                if (u==y)
                    break;
                else {
                    int v = p[u];
                    if (s[u][x] > s[u][v]) {
                        ++ans;
                        break;
                    }
                }
        }
        return ans;
    }
};