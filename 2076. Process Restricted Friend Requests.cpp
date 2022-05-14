class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x] = x==fa[x] ? x : fa[x]=find(fa[x]);
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        
        vector<bool> ans;
        for (auto& r : req) {
            int x = r[0], y = r[1];
            int fx = find(x), fy = find(y);
            if (fx == fy) {
                ans.push_back(true);
                continue;
            }
            for (auto& p : res) {
                int f1 = find(p[0]), f2 = find(p[1]);
                if (f1==fx && f2==fy || f1==fy && f2==fx) {
                    ans.push_back(false);
                    goto last;
                }
            }
            ans.push_back(true);
            fa[fx] = fy;
            last:
            continue;
        }
        return ans;
    }
};