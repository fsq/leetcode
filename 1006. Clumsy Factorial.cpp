class Solution {
public:
    int clumsy(int n) {
        int ans = 0;
        for (int i=n; i>=1; i-=4) {
            int a = i, b = max(i-1, 1), c = max(i-2, 1);
            ans += (i==n ? 1 : -1) * a*b/c + max(0, i-3);
        }
        return ans;
    }
};