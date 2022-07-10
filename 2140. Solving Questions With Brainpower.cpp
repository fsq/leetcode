class Solution {
public:
    long long mostPoints(vector<vector<int>>& a) {
        vector<long long> f(a.size());
        f.back() = a.back()[0];
        for (int i=(int)a.size()-2; i>=0; --i) {
            f[i] = max(f[i+1], (i+a[i][1]+1>=a.size() ? 0 : f[i+a[i][1]+1]) + a[i][0]);
        }
        return f[0];
    }
};