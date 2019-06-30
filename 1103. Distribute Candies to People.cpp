class Solution {
public:
    vector<int> distributeCandies(int s, int n) {
        int m = (sqrt(1+8*(double)s)-1) / 2;
        int round = m / n;
        vector<int> ans(n);
        for (int i=0; i<n; ++i) {
            ans[i] = (i+1+i+1+(round-1)*(long long)n) * round / 2;
            s -= ans[i];
        }
        for (int d=1+round*n, i=0; s>0; ++i, ++d) {
            ans[i] += min(d, s);
            s -= d;
        }
        return ans;
    }
};