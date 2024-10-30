class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        long long s=0, ss=0, n=a.size(), n2=n*n;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                s += a[i][j];
                ss += a[i][j] * a[i][j];
            }
        long long A = s - (1+n2)*n2/2; // x-y
        long long B = ss - n2*(n2+1)*(2*n2+1)/6; // (x+y)*(x-y)
        long long C = B / A;  // x+y
        int x = (A+C)/2, y = C - x;
        return {x, y};
    }
};