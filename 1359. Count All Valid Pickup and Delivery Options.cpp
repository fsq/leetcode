class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        const int M = 1e9 + 7;
        for (int i=2; i<=n; ++i) {
            ans = ans * ((i-1)*(2*i-1) + (2*i-1)) % M;
        }
        return ans;
    }
};