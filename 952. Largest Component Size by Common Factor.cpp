class Solution {
public:
    
    unordered_map<int, pair<int,int>> fa;
    
    int find(int x) {
        return fa[x].first==x ? x : fa[x].first=find(fa[x].first);
    }
    
    int largestComponentSize(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        vector<int> p;
        vector<int> vis(mx+1);
        for (int i=2; i<=mx; ++i) {
            if (!vis[i]) p.push_back(i);
            for (int j=0; j<p.size() && i*p[j]<=mx; ++j) {
                vis[i*p[j]] = true;
                if (i%p[j]==0) break;
            }
        }
        
        for (auto x : a) fa[x] = {x, 1};
        
        for (auto x : p) {
            int head = -1;
            for (int now=x; now<=mx; now+=x) 
                if (fa.count(now)) 
                    if (head==-1) 
                        head = now;
                    else {
                        int fx=find(head), fy=find(now);
                        if (fx != fy) {
                            fa[fy].first = fx;
                            fa[fx].second += fa[fy].second;
                        }
                    }
        }
        
        int ans = 0;
        for (auto& kv : fa) 
            if (kv.first==kv.second.first)
                ans = max(ans, kv.second.second);
        return ans;
    }
};