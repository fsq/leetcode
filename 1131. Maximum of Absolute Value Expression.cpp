class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        int n = a.size(), ans = INT_MIN;
        vector<int> m(4, INT_MAX);
        for (int x,i=0; i<n; ++i) 
            for (int k=0; k<4; ++k) {
                switch (k) {
                    case 0: x = a[i] + b[i] + i; break;
                    case 1: x = a[i] - b[i] + i; break;
                    case 2: x = b[i] - a[i] + i; break;
                    case 3: x = -a[i] - b[i] + i; break;
                }
                if (m[k] != INT_MAX) 
                    ans = max(ans, x-m[k]);
                m[k] = min(x, m[k]);
            }
        return ans;
    }
};