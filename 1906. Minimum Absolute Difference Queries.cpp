class Solution {
public:
    
    vector<int> minDifference(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        vector<vector<int>> v;
        for (int i=0; i<n; ++i) {
            vector<int> u = i==0 ? vector<int>(101) : v[i-1];
            ++u[a[i]];
            v.push_back(move(u));
        }
        vector<int> ans;
        for (auto& rg : q) {
            int l = rg[0], r = rg[1];
            int df = INT_MAX, pre = -1;
            for (int i=1; i<=100; ++i) 
                if (v[r][i]-(l==0 ? 0 : v[l-1][i]) > 0) {
                    if (pre!=-1) df = min(df, i - pre);
                    pre = i;
                }
            ans.push_back(df==INT_MAX ? -1 : df);
        }
        return ans;
    }
};