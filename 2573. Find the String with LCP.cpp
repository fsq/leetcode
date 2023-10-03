class Solution {
public:
    vector<int> fa;

    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i!=j && lcp[i][j]>0) {
                    int fi=find(i), fj=find(j);
                    if (fi != fj) {
                        fa[fi] = fj;
                    }
                }

        unordered_map<int, char> ind;
        int ch = 0;
        string ans;
        for (int i=0; i<n; ++i) {
            if (!ind.count(find(i))) {
                ind[find(i)] = 'a' + ch;
                ch = (ch+1) % 26;
            }
            ans.push_back(ind[find(i)]);
        }

        vector<vector<int>> f(n, vector<int>(n));
        f[n-1][n-1] = 1;
        for (int j=n-2; j>=0; --j) {
            f[j][n-1] = f[n-1][j] = ans[n-1]==ans[j];
        }
        for (int i=n-2; i>=0; --i)
            for (int j=n-2; j>=0; --j)
                f[i][j] = ans[i]==ans[j] ? (f[i+1][j+1]+1) : 0;
        return f==lcp ? ans : "";
    }
};