class Solution {
public:
    vector<int> avoidFlood(vector<int>& a) {
        int n = a.size();
        vector<int> p(n);
        unordered_map<int, int> last;
        set<int> slot;
        for (int i=0; i<n; ++i) {
            int x = a[i];
            p[i] = x ? -1 : 1;
            if (x) {
                if (!last.count(x)) {
                    last[x] = i;
                } else {
                    auto it = slot.upper_bound(last[x]);
                    if (it==slot.end()) return {};
                    p[*it] = x;
                    slot.erase(it);
                    last[x] = i;
                }
            } else {
                slot.insert(i);
            }
        }
        return p;
    }
};