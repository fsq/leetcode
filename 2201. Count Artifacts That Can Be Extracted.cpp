class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& dig) {
        vector<vector<int>> m(n, vector<int>(n));
        vector<int> cnt(a.size());
        for (int i=0; i<a.size(); ++i)
            for (int r=a[i][0]; r<=a[i][2]; ++r)
                for (int c=a[i][1]; c<=a[i][3]; ++c) {
                    ++cnt[i];
                    m[r][c] = i+1;
                }
        
        for (auto& p : dig)
            if (m[p[0]][p[1]]) {
                int& x = m[p[0]][p[1]];
                --cnt[x-1];
                x = 0;
            }
        
        return count(cnt.begin(), cnt.end(), 0);
    }
};