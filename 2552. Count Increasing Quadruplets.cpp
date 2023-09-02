class Solution {
public:
    long long countQuadruplets(vector<int>& a) {
        int n = a.size();
        vector<vector<long long>> jkl(n, vector<long long>(n)); // #l given j,k; 
        for (int j=1; j+2<n; ++j) {
            int lg = 0;
            for (int k=n-2; k>j; --k) {
                if (a[k+1] > a[j]) ++lg;
                if (a[k] < a[j]) {
                    jkl[j][k] = lg;
                }
            }
        }
        long long ans = 0;
        for (int k=n-2; k-2>=0; --k) {
            int ls = 0;
            for (int j=1; j<k; ++j) {
                if (a[j-1] < a[k]) ++ls;
                if (a[k] < a[j]) {
                    ans += ls * jkl[j][k];
                }
            }
        }
        return ans;
    }
};