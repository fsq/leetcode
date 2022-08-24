class Solution {
public:
    
    int best[1001];
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int most = 0;
        memset(best, 0x3f, sizeof(best));
        for (auto& tr : tires) {
            int i = 0;
            long long f = tr[0], r = tr[1], cost = f, cur = f;
            while (cur < changeTime+f) {
                ++i;
                best[i] = min<long long>(best[i], cost);
                cur *= r;
                cost += cur;
            }
            most = max(most, i);
        }
        vector<int> f(numLaps+1, INT_MAX);
        f[0] = 0;
        for (int i=1; i<=numLaps; ++i)
            for (int j=1; j<=min(i, most); ++j)
                f[i] = min(f[i], f[i-j]+best[j]+(i==j ? 0 : changeTime));
        return f[numLaps];
    }
};