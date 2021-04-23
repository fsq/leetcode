class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        int ans = 0;
        for (int i=0,j; i<a.size(); ) {
            int s = a[i];
            for (j=i+1; j<a.size() && a[j]>a[j-1]; ++j) {
                s += a[j];
            }
            ans = max(ans, s);
            i = j;
        }
        return ans;
    }
};