class Solution {
public:
    int minOperations(int k) {
        int q = ceil(sqrt(k));
        int a = max(0, q-1), b = a;
        int ans = a + b;
        if (a * (b+1) >= k) ans = a + b - 1;
        if ((a+1) * b >= k) ans = a + b - 1;
        return ans;
    }
};