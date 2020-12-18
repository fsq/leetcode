class Solution {
public:
    int boxDelivering(vector<vector<int>>& a, int portsCount, int maxBoxes, int maxWeight) {
        int n = a.size();
        vector<int> f(n, INT_MAX);
        for (int cost=0, j=0, i=0, w=0; i<n; ++i) {
            w += a[i][1];
            if (i>0 && a[i][0]!=a[i-1][0]) ++cost;
            
            while (i-j+1>maxBoxes || w>maxWeight || (j<i && j>0 && f[j-1]==f[j])) {
                w -= a[j][1];
                if (a[j][0] != a[j+1][0]) --cost;
                ++j;
            }
            f[i] = (j==0 ? 0 : f[j-1]) + cost + 2;
        }
        return f.back();
    }
};