class Solution {
public:

    int f[501][501];
    // f[n][w] = #ways of using n cards to build <=w width
    // f[n][w] = f[n][w-1] + f[n-(3*w-1)][w-1]
    int dp(int n, int w) {
        if (n==0) return 1;
        if (w==0) return 0;
        int& ans = f[n][w];
        if (ans != -1) return ans;
        ans = dp(n, w-1) + (3*w-1<=n ? dp(n-(3*w-1), w-1) : 0);
        return ans;
    }

    int houseOfCards(int n) {
        memset(f, -1, sizeof(f));
        return dp(n, (n+3)/3);
    }
};