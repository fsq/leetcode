class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& eg, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> e(n);
        for (int i=0; i<eg.size(); ++i) {
            e[eg[i][0]].push_back({eg[i][1], succProb[i]});
            e[eg[i][1]].push_back({eg[i][0], succProb[i]});
        }
        vector<double> d(n);
        vector<int> in(n);
        deque<int> q;
        d[start] = 1;
        in[start] = true;
        q.push_back(start);
        while (!q.empty()) {
            int x = q.front(); q.pop_front();
            in[x] = false;
            for (auto& pr : e[x])
                if (d[x] * pr.second > d[pr.first]) {
                    d[pr.first] = d[x] * pr.second;
                    if (!in[pr.first]) {
                        q.push_back(pr.first);
                        in[pr.first] = true;
                        if (d[q.back()] > d[q.front()]) {
                            swap(q.front(), q.back());
                        }
                    }
                }
        }
        return d[end];
    }
};