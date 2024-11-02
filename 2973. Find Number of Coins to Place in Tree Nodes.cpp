struct Info {
    int sz = 0;
    vector<long long> mx, mn;
};
class Solution {
public:
    vector<vector<int>> e;
    vector<long long> coin;
    int n;

    Info dfs(int x, vector<int>& cost, int pre=-1) {
        vector<long long> mx, mn;
        if (cost[x] > 0) 
            mx.push_back(cost[x]);
        else if (cost[x] < 0)
            mn.push_back(cost[x]);
        int sz = 1;
        for (auto y : e[x])
            if (y != pre) {
                auto info = dfs(y, cost, x);
                sz += info.sz;
                mx.insert(mx.end(), info.mx.begin(), info.mx.end());
                mn.insert(mn.end(), info.mn.begin(), info.mn.end());
            }
        sort(mx.rbegin(), mx.rend());
        sort(mn.begin(), mn.end());
        mx.resize(min<int>(mx.size(), 3));
        mn.resize(min<int>(mn.size(), 2));

        Info info;
        info.sz = sz;
        info.mx = mx;
        info.mn = mn;
        if (sz < 3) {
            coin[x] = 1;
            return info;
        }
        if (mx.size()==3) {
            coin[x] = max(coin[x], mx[0]*mx[1]*mx[2]);
        }
        if (mn.size()==2 && mx.size()>0) {
            coin[x] = max(coin[x], mn[0]*mn[1]*mx[0]);
        }
        return info;
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        n = cost.size();
        e.resize(n);
        coin.resize(n);
        for (auto& p: edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        dfs(0, cost);
        return coin;
    }
};