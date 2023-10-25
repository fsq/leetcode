class Solution {
public:
    int findMinimumTime(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int n = a.back()[1];
        vector<int> f(n+1);
        for (auto& pr : a) {
            int i = pr[0], j = pr[1], v = pr[2];
            int cur = accumulate(f.begin()+i, f.begin()+j+1, 0);
            if (cur >= v) continue;
            for (int x=j; cur<v; --x)
                if (f[x] == 0) {
                    f[x] = 1;
                    ++cur;
                }
        }
        return accumulate(f.begin(), f.end(), 0);
    }
};