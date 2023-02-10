class Solution {
public:
    long long minimumReplacement(vector<int>& a) {
        int i = 0;
        for (i = a.size()-1; i-1>=0 && a[i]>=a[i-1]; --i);
        int x = a[i];
        long long ans = 0;
        while (i >= 1) {
            if (a[i-1] <= x) {
                x = a[i-1];
            } else {
                int split = (x+a[i-1]-1) / x;
                ans += split - 1;
                x = a[i-1] / split;
            }
            --i;
        }
        return ans;
    }
};