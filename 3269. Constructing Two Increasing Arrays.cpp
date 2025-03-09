class Solution {
public:

    int f[1001][1001];

    int dp(vector<int>& a, vector<int>& b, int i, int j) {
        if (i==0 && j==0) return 0;
        int& ans = f[i][j];
        if (ans != -1) return ans;
        ans = INT_MAX;
        if (i > 0) {
            int cur = dp(a, b, i-1, j) + 1;
            if ((cur & 1) != a[i-1]) ++cur;
            ans = cur;
        }
        if (j > 0) {
            int cur = dp(a, b, i, j-1) + 1;
            if ((cur & 1) != b[j-1]) ++cur;
            ans = min(ans, cur);
        }
        return ans;
    }

    int minLargest(vector<int>& a, vector<int>& b) {
        memset(f, -1, sizeof(f));
        return dp(a, b, a.size(), b.size());
    }
};
