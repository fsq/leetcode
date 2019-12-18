class Solution {
public:
    int maxSideLength(vector<vector<int>>& a, int threshold) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> s(n+1, vector<int>(m+1));
        auto sum = [&](int x, int y, int l) {
            return s[x+1][y+1] - s[x-l+1][y+1] - s[x+1][y-l+1] + s[x-l+1][y-l+1];  
        };
        int l = 0;
        for (int i=0; i<n; ++i) 
            for (int j=0; j<m; ++j) {
                s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
                while (i>=l && j>=l && sum(i, j, l+1)<=threshold) ++l;
            }
        
        return l;
    }
};