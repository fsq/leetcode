class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        if (a.empty() || b.empty()) return {};
        int n = a.size(), m = b.size();
        multiset<vector<int>> st;
        for (int i=0; i<n; ++i)
            st.insert({a[i]+b[0], i, 0});
        vector<vector<int>> ans;
        while (ans.size() < k && st.size()) {
            auto p = *st.begin();
            st.erase(st.begin());
            int i = p[1], j = p[2];
            ans.push_back({a[i], b[j]});
            if (++j < m)
                st.insert({a[i]+b[j], i, j});
        }
        return ans;
    }
};