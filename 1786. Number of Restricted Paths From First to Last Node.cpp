using PII = pair<int,int>;
class Solution {
public:
    
    int dfs(vector<vector<int>>& e, vector<long long>& f, int x, int n) {
        if (x==n) return 1;
        if (f[x] != -1) return f[x];
        long long& ans = f[x];
        ans = 0;
        for (auto y : e[x]) {
            ans = (ans + dfs(e, f, y, n)) % 1000000007;
        }
        return ans;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> e(n+1);
        for (auto& pr : edges) {
            e[pr[0]].push_back({pr[1], pr[2]});
            e[pr[1]].push_back({pr[0], pr[2]});
        }
        vector<int> d(n+1, INT_MAX);
        {
            priority_queue<PII, vector<PII>, std::greater<PII>> q;
            q.push({0, n});
            d[n] = 0;
            while (q.size()) {
                auto pr = q.top(); q.pop();
                if (pr.first > d[pr.second]) continue;
                for (auto x : e[pr.second]) {
                    if (d[pr.second] + x.second < d[x.first]) {
                        d[x.first] = d[pr.second] + x.second;
                        q.push({d[x.first], x.first});
                    }
                }
            }
        }
        vector<vector<int>> es(n+1);
        for (auto& pr : edges) 
            if (d[pr[0]] > d[pr[1]]) {
                es[pr[0]].push_back(pr[1]);
            } else if (d[pr[0]] < d[pr[1]]) {
                es[pr[1]].push_back(pr[0]);
            }
        vector<long long> f(n+1, -1);
        return dfs(es, f, 1, n);
    }
};