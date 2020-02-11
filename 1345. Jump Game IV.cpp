class Solution {
public:
    int minJumps(vector<int>& a) {
        if (a.size()==1) return 0;
        
        unordered_map<int, vector<int>> p;
        for (int i=0; i<a.size(); ++i) p[a[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        vector<int> vis(a.size());
        vis[0] = true;
        for (int stp=1; ;++stp) 
            for (int t=q.size(), k=0; k<t; ++k) {
                int x = q.front(); q.pop();
                for (int d=-1; d<=1; d+=2)
                    if (x+d>=0 && x+d<a.size() && !vis[x+d]) {
                        if (x+d+1==a.size()) return stp;
                        vis[x+d] = true;
                        q.push(x+d);
                    }
                if (p.count(a[x])) {
                    for (auto y : p[a[x]]) {
                        vis[y] = true;
                        if (y+1==a.size()) return stp;
                        q.push(y);
                    }
                    p.erase(a[x]);
                }
            }
        return 0;
    }
};