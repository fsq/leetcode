class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int> now = a[0];
        int n = a.size(), m = a[0].size();
        if (m > k) now.resize(k);
        for (int i=1; i<n; ++i) {
            set<vector<int>> st;
            for (int j=0; j<m; ++j) st.insert({a[i][j]+now[0], j, 0});
            vector<int> nxt;
            while (nxt.size()<k && st.size()) {
                auto pr = *st.begin();
                st.erase(st.begin());
                nxt.push_back(pr[0]);
                if (pr[2]+1<now.size()) {
                    st.insert({a[i][pr[1]]+now[pr[2]+1], pr[1], pr[2]+1});
                }
            }
            now = std::move(nxt);
        }
        return now.back();
    }
};