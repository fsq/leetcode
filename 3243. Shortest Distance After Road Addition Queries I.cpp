class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> e(n);
        vector<int> f(n);
        for (int i=0; i+1<n; ++i) {
            e[i].push_back(i+1);
            f[i] = i;
        }
        f[n-1] = n-1;
        vector<int> ans;
        for (auto& pr : q) {
            int x=pr[0], y=pr[1];
            e[x].push_back(y);
            for (int x=0; x+1<n; ++x)
                for (int y: e[x]) {
                    f[y] = min(f[y], f[x]+1);
                }
            ans.push_back(f[n-1]);
        }
        return ans;
    }
};