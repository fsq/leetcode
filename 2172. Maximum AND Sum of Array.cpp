class Solution {
public:
    int maximumANDSum(vector<int>& a, int numSlots) {
        a.resize(numSlots * 2);
        int n = a.size();
        vector<int> f(1<<n);
        for (int i=1; i<(1<<n); ++i) {
            int b = (__builtin_popcount(i) + 1) / 2;
            for (int j=0; j<a.size(); ++j) 
                if ((i >> j) & 1) {
                    f[i] = max(f[i], f[i ^ (1<<j)] + (b & a[j]));
                }
        }
        return f.back();
    }
};