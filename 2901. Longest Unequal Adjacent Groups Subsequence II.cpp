class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& a, vector<int>& groups) {
        int n = a.size();
        vector<vector<int>> d(n, vector<int>(n, -1));
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j) 
                if (a[i].size()==a[j].size() && groups[i]!=groups[j]) {
                    d[i][j] = 0;
                    for (int k=0; k<a[i].size(); ++k)
                        if (a[i][k] != a[j][k]) 
                            ++d[i][j];
                    d[j][i] = d[i][j];
                }
        vector<int> f(n), g(n, -1);
        for (int i=0; i<n; ++i) {
            f[i] = 1;
            for (int j=0; j<i; ++j)
                if (d[j][i]==1 && f[j]+1>f[i]) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }  
        }
        int i = max_element(f.begin(), f.end()) - f.begin();
        vector<string> ans;
        while (i != -1) {
            ans.push_back(a[i]);
            i = g[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};