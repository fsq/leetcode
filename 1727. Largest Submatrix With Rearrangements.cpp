class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for (int i=0; i<n; ++i) {
            vector<int> s;
            for (int j=0; j<m; ++j) {
                a[i][j] = (a[i][j] && i>0) ? a[i-1][j]+1 : a[i][j];
                s.push_back(a[i][j]);
            }
            sort(s.begin(), s.end(), std::greater<int>());
            for (int i=0; i<m; ++i) 
                ans = max(ans, (i+1) * s[i]);
        }
        return ans;
    }
};