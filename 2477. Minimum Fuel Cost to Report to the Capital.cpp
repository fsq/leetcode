class Solution {
public:

    // cost, #people
    pair<long long,int> dfs(vector<vector<int>>& e, int seats, int x, int fa) {
        long long cost = 0;
        int people = 1;
        for (auto y : e[x])
            if (y != fa) {
                auto sub = dfs(e, seats, y, x);
                people += sub.second;
                cost += sub.first;
            }
        if (fa != -1) {
            long long bus = (people+seats-1)/seats;
            cost += bus;
        }
        return {cost, people};
    }

    long long minimumFuelCost(vector<vector<int>>& a, int seats) {
        int n = a.size() + 1;
        vector<vector<int>> e(n);
        for (auto& pr : a) {
            e[pr[0]].push_back(pr[1]);
            e[pr[1]].push_back(pr[0]);
        }
        auto pr = dfs(e, seats, 0, -1);
        return pr.first;
    }
};