class Solution {
public:
    long long maxProfit(vector<int>& w, vector<vector<int>>& t) {
        unordered_map<int, int> ws;
        unordered_map<int, multiset<int, std::greater<int>>> ts;
        for (auto x : w) ++ws[x];
        for (auto pr : t) ts[pr[0]].insert(pr[1]);
        int rem_max = 0;
        long long ans = 0;
        for (auto& [sk, st]: ts) {
            auto it = st.begin();
            for (int i=0; i<ws[sk] && it!=st.end(); ++i, ++it) {
                ans += *it;
            }
            if (it != st.end()) rem_max = max(rem_max, *it);
        }
        ans += rem_max;
        return ans;
    }
};