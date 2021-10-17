class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j) {
                int m = sqrt(i*i+j*j);
                if (m<=n && m*m == i*i+j*j)
                    ++ans;
            }
        return ans;
    }
};