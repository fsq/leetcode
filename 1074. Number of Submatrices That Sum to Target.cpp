class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for (int i=0; i<n; ++i) {
            vector<int> s(m);
            for (int j=i; j<n; ++j) {
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                for (int pre=0, k=0; k<m; ++k) {
                    s[k] += a[j][k];
                    pre += s[k];
                    auto it = cnt.find(pre-target);
                    if (it != cnt.end())
                        ans += it->second;
                    ++cnt[pre];
                }
            }
        }
        return ans;
    }
};