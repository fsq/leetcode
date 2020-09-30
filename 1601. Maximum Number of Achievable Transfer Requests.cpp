class Solution {
public:
    
    int ans = 0, gift = 0;
    
    void dfs(vector<vector<int>>& req, vector<int>& a, int i, int nz, int chose) {
        if (i==req.size()) {
            if (nz==0) ans = max(ans, chose+gift);
        } else {
            if (chose + gift + req.size() - i <= ans) return;
            
            int& x = a[req[i][0]];
            int& y = a[req[i][1]];
            --x, ++y;
            if (x==0) --nz; else if (x==-1) ++nz;
            if (y==0) --nz; else if (y==1) ++nz;
            dfs(req, a, i+1, nz, chose+1);
            ++x, --y;
            if (x==0) --nz; else if (x==1) ++nz;
            if (y==0) --nz; else if (y==-1) ++nz;
            
            dfs(req, a, i+1, nz, chose);
        }
    }
    
    int maximumRequests(int n, vector<vector<int>>& req) {
        
        for (auto it=req.begin(); it!=req.end(); )
            if ((*it)[0]==(*it)[1]) {
                ++gift;
                it = req.erase(it);
            } else 
                ++it;
        ans = gift;
        
        sort(req.begin(), req.end());
        for (auto& q : req) cout << q[0] << ' ' << q[1] << endl;
        vector<int> a(n);
        dfs(req, a, 0, 0, 0);
        return ans;
    }
};