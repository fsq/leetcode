class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> e(n);
        for (auto& p : edges) {
            e[p[0]].push_back(vals[p[1]]);
            e[p[1]].push_back(vals[p[0]]);
        }
        int ans = INT_MIN;
        for (int i=0; i<n; ++i) {
            ans = max(ans, vals[i]);
            auto& a = e[i];
            sort(a.rbegin(), a.rend());
            int s = 0;
            for (int j=0; j<a.size() && j<k && a[j]>0; ++j) s += a[j];
            ans = max(ans, vals[i]+s);
        }
        return ans==INT_MIN ? 0 : ans;
    }
};