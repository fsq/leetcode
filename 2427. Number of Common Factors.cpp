class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int i=1; i<=sqrt(a); ++i)
            if (a%i == 0) {
                int j = a / i;
                if (b%i==0) ++ans;
                if (i!=j && b%j==0) ++ans;
            }
        return ans;
    }
};