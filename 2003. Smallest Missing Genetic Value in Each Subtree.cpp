class Solution {
public:
    
    int n, p;
    vector<int> vis, ans;
    
    void collect(vector<vector<int>>& e, vector<int>& a, int x, int skip=-1) {
        if (a[x]<vis.size()) vis[a[x]] = true;
        for (auto y : e[x]) 
            if (y != skip)
                collect(e, a, y);
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& pr, vector<int>& nums) {
        n = pr.size();
        vis.resize(n+2);
        p = 1;
        ans.resize(n, 1);
        vector<vector<int>> e(n);
        
        int n1 = 0;
        for (int i=1; i<n; ++i) {
            if (nums[i] == 1) n1 = i;
            e[pr[i]].push_back(i);
        }
        
        int son = -1;
        while (n1 != -1) {
            collect(e, nums, n1, son);
            while (vis[p]) ++p;
            ans[n1] = p;
            son = n1;
            n1 = pr[n1];
        }
        return ans;
    }
};