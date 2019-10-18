class Solution {
public:
    int maxEqualFreq(vector<int>& a) {
        vector<int> f(100001), c(100001);
        int ans = 0, nc = 0;
        for (int x,i=0; i<a.size(); ++i) {
            x = a[i];
            if (nc==1) ans = i + 1;
            if (--c[f[x]]==0) --nc;
            if (++c[++f[x]]==1) ++nc;
            if (nc==2 && (c[f[x]+1]==1 || c[1]==1)) ans = i + 1;
        }
        return ans;
    }
};