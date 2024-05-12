class Solution {
public:
    vector<int> s;
    bool f[101][101];
    int n;

    bool canSplitArray(vector<int>& a, int m) {
        n = a.size();
        s.resize(n);
        partial_sum(a.begin(), a.end(), s.begin());
        memset(f, 0, sizeof(f));
        for (int i=0; i<n; ++i) f[i][i] = true;
        for (int l=2; l<=n; ++l) {
            for (int i=0; i+l-1<n; ++i) {
                int j = i + l -1;
                for (int k=i; k<j; ++k) { // [i, k] [k+1, j]
                    int s1 = s[k] - (i==0 ? 0 : s[i-1]);
                    int s2 = s[j] - s[k];
                    f[i][j] = (f[i][k] && (i==k || s1>=m)) && (f[k+1][j] && (k+1==j || s2>=m));
                    if (f[i][j]) break;
                }
            }
        }
        return f[0][n-1];
    }
};