class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) {
        set<int, std::greater<int>> st;
        int n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                st.insert(a[i][j]);
                for (int l=2; j-l+1>=0 && j+l<=m && i+l+l-2<n; ++l) {
                    int tot = a[i][j] + a[i+l+l-2][j];
                    for (int k=1; k<l; ++k) {
                        tot += a[i+k][j+k] + a[i+k][j-k];
                        tot += a[i+l+l-2-k][j+k] + a[i+l+l-2-k][j-k];
                    }
                    tot -= a[i+l-1][j+l-1] + a[i+l-1][j-l+1];
                    st.insert(tot);
                }
                while (st.size()>3) st.erase(prev(st.end()));
            }
        return vector<int>(st.begin(), st.end());
    }
};