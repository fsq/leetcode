class Solution {
public:
    int n, m;
    
    int count(vector<int>& a) {
        stack<int> s;
        vector<int> ans(m+1);
        for (int i=1; i<=m; ++i) {
            while (s.size() && a[i]<a[s.top()]) s.pop();
            if (s.empty()) {
                ans[i] = a[i] * i;
            } else {
                ans[i] = ans[s.top()] + a[i] * (i - s.top());
            }
            s.push(i);
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
    
    int numSubmat(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        vector<int> h(m+1);
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j)
                h[j+1] = a[i][j] ? h[j+1]+1 : 0;
            ans += count(h);
        }
        return ans;
    }
};