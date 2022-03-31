class Solution {
public:
    
    int calc(int time, int change, int ne) {
        int ans = 0;
        while (ne--) {
            ans += time;
            if (((ans/change) & 1) && ne>0) {
                ans = (ans + change*2-1) / (change*2) * (change*2);
            }
        }
        return ans;
    }
    
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> e(n+1);
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        vector<int> vis(n+1), md(n+1);
        vis[1] = 1;
        queue<pair<int,int>> q;
        q.push({1, 0});
        int m1=INT_MIN, m2=INT_MIN; //min_step, 2nd_min_step
        while (q.size()) {
            int x=q.front().first, t=q.front().second;
            q.pop();
            int nt = t + 1;
            for (auto y : e[x]) 
                if (vis[y] < 2 && nt > md[y]) {
                    ++vis[y];
                    md[y] = nt;
                    q.push({y, t+1});
                    if (y==n) {
                        if (vis[y]==1) m1 = nt; else m2 = nt;
                    }
                }
        }
        return calc(time, change, m2);
    }
};