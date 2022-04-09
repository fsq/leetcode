class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        map<int, int> m;
        for (auto& e : events)
            m[e[1]] = max(m[e[1]], e[2]);
        
        int ans = 0, prev = 0;
        auto it = m.begin();
        for (auto& e : events) {
            while (it!=m.end() && it->first<e[0]) {
                prev = max(prev, it->second);
                ++it;
            }
            ans = max(ans, prev + e[2]);
        }
        return ans;
    }
};