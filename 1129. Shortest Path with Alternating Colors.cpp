class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<int>> d(n, vector<int>(2, -1));
        vector<vector<int>> a(n), b = a;
        for (auto& e : red) 
            a[e[0]].push_back(e[1]);
        
        for (auto& e : blue) 
            b[e[0]].push_back(e[1]);
        
        d[0][0] = d[0][1] = 0;
        
        queue<vector<int>> q;
        q.push({0, 0});
        q.push({0, 1});
        for (int x,c; !q.empty(); q.pop()) {
            x = q.front()[0];
            c = q.front()[1];
            int dis = d[x][c];
            auto& e = c ? b : a;
            c ^= 1;
            for (auto y : e[x])
                if (d[y][c]==-1) {
                    d[y][c] = dis + 1;
                    q.push({y, c});
                }
        }
        vector<int> ans;
        for (auto& a : d)
            ans.push_back(a[0]==-1 ? a[1] : (a[1]==-1 ? a[0] : min(a[0], a[1])));
        return ans;
    }
};