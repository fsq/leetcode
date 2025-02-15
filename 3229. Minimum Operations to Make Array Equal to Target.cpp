class Solution {
public:
    long long minimumOperations(vector<int>& a, vector<int>& b) {
        for (int i=0; i<a.size(); ++i) {
            a[i] = b[i] - a[i];
        }   
        long long ans = 0;
        for (int j=0,i=0; i<a.size(); )
            if (a[i] != 0) {
                for (j=i; j<a.size() && a[j] && signbit(a[j])==signbit(a[i]); ++j) {
                    int pre = j==i ? 0 : a[j-1];
                    if (!signbit(a[i])) {
                        ans += max(0, a[j]-pre);
                    } else {
                        ans += max(0, pre-a[j]);
                    }
                }
                i = j;
            } else {
                ++i;
            }
        return ans;
    }
};