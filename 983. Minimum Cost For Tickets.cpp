class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        days.insert(days.begin(), INT_MIN);
        vector<int> f(n+1, INT_MAX);
        f[0] = 0;
        for (int j,i=1; i<=n; ++i) {
            f[i] = f[i-1] + costs[0];
            for (j=i-1; days[j]>=days[i]-6; --j) 
                f[i] = min(f[i], f[j]+min(costs[1], costs[2]));
            f[i] = min(f[i], f[j]+costs[1]);
            for (; days[j]>=days[i]-29; --j)
                f[i] = min(f[i], f[j]+costs[2]);
            f[i] = min(f[i], f[j]+costs[2]);
        }
        return f.back();
    }
};