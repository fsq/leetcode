class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
        
        for (int i=threshold+1; i<=n/2; ++i)
            for (int j=i*2; j<=n; j+=i) {
                int fx = find(i), fy = find(j);
                if (fx != fy) 
                    fa[fy] = fx;
            }
        
        vector<bool> ans;
        for (auto& pr : queries) {
            int fx = find(pr[0]), fy = find(pr[1]);
            ans.push_back(fx == fy);
        }
        return ans;
    }
};