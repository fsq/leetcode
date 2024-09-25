class Solution {
public:
    int minimumCoins(vector<int>& a) {
        a.push_back(0);
        vector<int> f(a.size());
        for (int i=a.size()-2; i>=0; --i) {
            int m = INT_MAX;
            for (int j=i+1; j<f.size() && j<=2*i+2; ++j) {
                m = min(m, f[j]);
            }
            f[i] = a[i] + m;
        }
        return f[0];
    }
};