class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int, int> sell, buy;
        for (auto& o : orders)  {
            if (o[2] == 0) {
                buy[o[0]] += o[1];
            } else {
                sell[o[0]] += o[1];
            }
            while (buy.size() && sell.size() && (prev(buy.end())->first >= sell.begin()->first)) {
                auto b = prev(buy.end()), s = sell.begin();
                int done = min(b->second, s->second);
                b->second -= done;
                if (b->second == 0) buy.erase(b);
                s->second -= done;
                if (s->second == 0) sell.erase(s);
            }
        }
        int ans = 0;
        for (auto& pr : buy) ans = (ans + pr.second) % 1000000007;
        for (auto& pr : sell) ans = (ans + pr.second) % 1000000007;
        return ans;
    }
};