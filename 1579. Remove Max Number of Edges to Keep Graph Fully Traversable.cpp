class Solution {
public:
    
    int find(vector<int>& fa, int x) {
        return fa[x]==x ? x : fa[x] = find(fa, fa[x]);
    }
    
    int calc(vector<vector<int>>& eg, vector<int> fa, int cc, int tp) {
        int ans = 0;
        for (auto& p : eg)
            if (p[0]==tp) {
                int x = p[1], y = p[2], fx = find(fa, x), fy = find(fa, y);
                if (fx != fy) {
                    fa[fx] = fy;
                    --cc;
                    ++ans;
                }
            }
        if (cc > 1) return -1;
        return ans;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& eg) {
        vector<int> fa(n+1);
        iota(fa.begin(), fa.end(), 0);
        int cc = n, ans = 0;
        for (auto& p : eg)
            if (p[0]==3) {
                int x = p[1], y = p[2], fx = find(fa, x), fy = find(fa, y);
                if (fx != fy) {
                    fa[fx] = fy;
                    --cc;
                    ++ans;
                }
            }
        
        int c1 = calc(eg, fa, cc, 1);
        if (c1 == -1) return -1;
        int c2 = calc(eg, fa, cc, 2);
        if (c2 == -1) return -1;
        return eg.size() - (ans + c1 + c2);
    }
};