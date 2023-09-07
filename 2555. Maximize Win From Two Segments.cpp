class Solution {
public:
    int maximizeWin(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> f(n+1);
        for (int i=0, j=0; j<a.size(); ++j) {
            while (a[j]-a[i]>k) ++i;
            ans = max(ans, j-i+1 + (i==0 ? 0 : f[i-1]));
            f[j] = max(j==0 ? 0 : f[j-1], j-i+1);
        }
        return ans;
    }
};