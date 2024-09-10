class Solution {
public:
    vector<vector<int>> e;
    int n, k;

    vector<int> dp(int x, vector<int>& c, int pre=-1) {
        vector<vector<int>> ys;
        for (auto y : e[x])
            if (y != pre) {
                auto dy = dp(y, c, x);
                ys.push_back(dy);
            }
        
        vector<int> f(15);
        for (int t=c[x], i=0; i<=14; ++i, t/=2) {
            int f0 = t - k;
            int f1 = t / 2;
            for (auto& y : ys) {
                f0 += y[i];
                f1 += (i+1>14) ? 0 : y[i+1];
            }
            f[i] = max(f0, f1);
        }
        return f;
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int _k) {
        n = coins.size();
        e.resize(n);
        k = _k;
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }    
        auto ans = dp(0, coins);
        return ans[0];
    }
};