class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int f0=0, f1=1;
        for (int i=1; i<a.size(); ++i) {
            int g0=INT_MAX, g1=INT_MAX;
            if (a[i]>a[i-1] && b[i]>b[i-1]) {
                g0 = f0;
                g1 = f1 + 1;
            }
            if (a[i]>b[i-1] && b[i]>a[i-1]) {
                g0 = min(g0, f1);
                g1 = min(g1, f0 + 1);
            }
            f0 = g0;
            f1 = g1;
        }
        return min(f1, f0);
    }
};