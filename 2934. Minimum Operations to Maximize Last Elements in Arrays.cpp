class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int m1=a.back(), m2=b.back(), nop=0;
        int ans = 0;
        for (int i=0; i+1<a.size(); ++i) {
            if (max(a[i], b[i])<=min(m1, m2)) ++nop;
            if (a[i] > m1 || b[i] > m2) {
                swap(a[i], b[i]);
                ++ans;
            }
            if (!(a[i]<=m1 && b[i]<=m2)) {
                return -1;
            }
        }
        return min<int>(ans, a.size() - nop - ans);
    }
};