class Solution {
public:
    
    int count(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<vector<int>> r(n, vector<int>(m)), c = r;
        for (int i=0; i<n; ++i) 
            for (int j=m-1; j>=0; --j)
                if (a[i][j] == 1) {
                    r[i][j] = (j+1==m) ? 1 : (r[i][j+1]+1);
                    c[i][j] = 1;
                    if (r[i][j]>=3 && i-1>=0 && j+1<m && a[i-1][j+1]==1) {
                        c[i][j] = min((r[i][j]+1)/2, c[i-1][j+1]+1);
                        ans += c[i][j] - 1;
                    }
                }
        return ans;
    }
    
    int countPyramids(vector<vector<int>>& a) {
        int ans = count(a);
        reverse(a.begin(), a.end());
        return ans + count(a);
    }
};