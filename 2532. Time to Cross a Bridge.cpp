class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<vector<int>> ev; // {-time, ltr+rtl, index, pos}
        priority_queue<vector<int>> ql, qr; // {ltr+rtl, index, time}
        for (int i=0; i<k; ++i) {
            ql.push({time[i][0]+time[i][2], i, 0});
        }
        int t = 0;
        while (n || ev.size() || qr.size()) {
            if ((!n || ql.empty()) && qr.empty()) t = max(t, -ev.top()[0]);
            while (ev.size() && -ev.top()[0] <= t) {
                auto v = ev.top(); ev.pop();
                if (v[3] == 0) {
                    ql.push({v[1], v[2], -v[0]});
                } else {
                    qr.push({v[1], v[2], -v[0]});
                }
            }
            if (n && (qr.empty() || (ql.size() && -ql.top()[0]<-qr.top()[0] && t<-qr.top()[0]))) {
                auto v = ql.top(); ql.pop();
                int i = v[1];
                t = max(t, -v[2]);
                ev.push({-(t+time[i][0]+time[i][1]), time[i][0]+time[i][2], i, 1});
                t += time[i][0];
                --n;
            } else if (qr.size()) {
                auto v = qr.top(); qr.pop();
                int i = v[1];
                t = max(t, -v[2]);
                if (n) ev.push({-(t+time[i][2]+time[i][3]), time[i][0]+time[i][2], i, 0});
                t += time[i][2];
            }
        }
        return t;
    }
};