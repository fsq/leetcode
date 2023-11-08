class Solution {
public:
    int minNumber(vector<int>& a, vector<int>& b) {
        vector<int> f(10), g(10);
        for (auto x : a) f[x] = 1;
        for (auto x : b) g[x] = 1;
        for (int i=1; i<=9; ++i)
            if (f[i] && g[i])
                return i;
        for (int i=11; i<=99; ++i)
            if ((f[i/10] && g[i%10]) || (f[i%10] && g[i/10]))
                return i;
        return 0;
    }
};