class Solution {
public:

    int dfs(vector<vector<int>>& e, vector<int>& a, int bound, int x, int fa=-1) {
        int tot = a[x];
        for (auto y : e[x])
            if (y != fa) {
                int sub = dfs(e, a, bound, y, x);
                if (sub==-1) return -1;
                tot += sub;
            }
        if (tot > bound) return -1;
        if (tot == bound) return 0;
        return tot;
    }

    int componentValue(vector<int>& a, vector<vector<int>>& edges) {
        int sum=0, mn=INT_MAX;
        vector<vector<int>> e(a.size());
        for (auto& pr : edges) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        for (auto x : a) {
            sum += x;
            mn = min(mn, x);
        }
        int ans = 0;
        for (int i=1; i<=sqrt(sum); ++i) 
            if (sum % i == 0) {
                if (dfs(e, a, i, 0) != -1) return sum/i-1;
                if (sum/i != i && dfs(e, a, sum/i, 0) != -1) ans = max(ans, i-1);
            }
        return ans;
    }
};