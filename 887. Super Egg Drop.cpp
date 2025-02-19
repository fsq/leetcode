class Solution {
public:
    // f[n][k] = 1 + min i of max(f[i-1][k-1], f[n-i][k])
    // f[0][x] = 0  f[x][1] = x

    int f[10001][101];


    int dp(int n, int k) {
        if (k==1) return n;
        if (n==0) return 0;
        int& ans = f[n][k];
        if (ans != -1) return ans;

        int l=1, r=n;
        ans = INT_MAX;
        // max(a, b), a is increasing, b is decresing,
        // optimal point is where a intersect with b, i.e. a~=b
        while (l <= r) {
            int mid = (l+r) >> 1;
            int d1 = dp(mid-1, k-1);
            int d2 = dp(n-mid, k);
            ans = min(ans, 1+max(d1,d2));
            if (d1 < d2) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int superEggDrop(int k, int n) {
        memset(f, -1, sizeof(f));
        return dp(n, k);        
    }
};