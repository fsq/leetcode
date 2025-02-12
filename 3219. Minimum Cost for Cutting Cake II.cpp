class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& a, vector<int>& b) {
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        long long ans = 0;

        int i=0, j=0;
        while (i<a.size() || j<b.size()) {
            if (i<a.size() && (j==b.size() || 
            // a[i]*(j+1)+b[j]*(i+2))<=(a[i]*(j+2)+b[j]*(i+1)  ==> a[i]>=b[j]
                a[i]>=b[j])) {
                ans += a[i] * (j+1);
                ++i;
            } else {
                ans += b[j] * (i+1);
                ++j;
            }
        }
        return ans;
    }
};