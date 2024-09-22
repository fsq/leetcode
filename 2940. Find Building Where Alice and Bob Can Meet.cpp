class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& qr) {
        vector<vector<int>> q;
        for (int i=0; i<qr.size(); ++i) {
            if (qr[i][0] > qr[i][1]) {
                swap(qr[i][0], qr[i][1]);
            }
            q.push_back({qr[i][1], qr[i][0], i});
        }
        sort(q.rbegin(), q.rend());
        vector<int> ans(qr.size(), -1);
        deque<int> dq;
        int pi = h.size() - 1;
        for (auto& qr : q) {
            int y = qr[1], x = qr[0], qi = qr[2];
            if (y == x || h[y] < h[x]) {
                ans[qi] = x;
                continue;
            }
            // push [x+1,...,pi]
            for (; pi>x; --pi) {
                while (dq.size() && h[pi]>=h[dq.front()]) {
                    dq.pop_front();
                }
                dq.push_front(pi);
            }
            // find first > ht
            auto i = upper_bound(dq.begin(), dq.end(), max(h[x], h[y]), [&](int ht, int x) {
                return h[x] > ht;
            }) - dq.begin();
            if (i < dq.size()) {
                ans[qi] = dq[i];
            }
        }
        return ans;
    }
};