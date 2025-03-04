class Solution {
public:
    int maxScore(vector<int>& a) {
        vector<int> f(a.size());
        for (int i=1; i<a.size(); ++i)
            for (int j=0; j<i; ++j)
                f[i] = max(f[i], f[j] + a[i]*(i-j));
        return f.back();
    }
};