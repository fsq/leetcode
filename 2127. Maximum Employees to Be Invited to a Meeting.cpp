class Solution {
public:
    int n;
    
    int maxd(vector<vector<int>>& e, int x, int ban) {
        int d = 0;
        for (int y : e[x])
            if (y != ban)
                d = max(maxd(e, y, -1)+1, d);
        return d;
    }
    
    int maximumInvitations(vector<int>& fav) {
        n = fav.size();
        vector<vector<int>> e(n);
        vector<pair<int,int>> c2;
        for (int i=0; i<n; ++i) {
            e[fav[i]].push_back(i);
            if (i<fav[i] && fav[fav[i]]==i) c2.push_back({i, fav[i]});
        }

        int ansc2 = 0;
        for (auto& c : c2) {
            ansc2 += maxd(e, c.first, c.second)+maxd(e, c.second, c.first)+2;
        }
        vector<int> vis(n);
        int maxcir = 0;
        for (int it=1, i=0; i<n; ++i)
            if (!vis[i]) {
                int x = i;
                do {
                    vis[x] = it;
                    x = fav[x];
                } while (!vis[x]);
                if (vis[x] == it) {
                    int cirlen = 0;
                    for (int y=x; fav[y]!=x; y=fav[y]) {
                        ++cirlen;
                    }
                    maxcir = max(maxcir, cirlen+1);
                }
                ++it;
            }
        return max(ansc2, maxcir);
    }
};