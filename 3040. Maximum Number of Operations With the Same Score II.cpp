class Solution {
public:
    int f[2001][2001];

    int dp(vector<int>& a, int i, int j, int target) {
        if (j-i+1<2) return 0;
        int& ans = f[i][j];
        if (ans != -1) return ans;
        ans = 0;
        if (a[i]+a[i+1] == target) ans = max(ans, dp(a, i+2, j, target)+1);
        if (a[j-1]+a[j] == target) ans = max(ans, dp(a, i, j-2, target)+1);
        if (a[i]+a[j] == target) ans = max(ans, dp(a, i+1, j-1, target)+1);
        return ans;
    }

    int maxOperations(vector<int>& a) {
        int ans = 0;
        memset(f, -1, sizeof(f));
        ans = max(ans, dp(a, 2, a.size()-1, a[0]+a[1]) + 1);
        // Can't reach same f[i][j] with different sum
        // memset(f, -1, sizeof(f));
        ans = max(ans, dp(a, 0, a.size()-3, a[a.size()-1]+a[a.size()-2]) + 1);
        // memset(f, -1, sizeof(f));
        ans = max(ans, dp(a, 1, a.size()-2, a[0]+a.back()) + 1);
        return ans;
    }
};