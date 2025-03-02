class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& a) {
        // find top3 in each row
        vector<vector<pair<long long,int>>> r;
        for (auto& row : a) {
            set<pair<long long,int>, std::greater<pair<long long,int>>> st;
            for (int j=0; j<row.size(); ++j) {
                st.insert({row[j], j});
                if (st.size() > 3)
                    st.erase(prev(st.end()));
            }
            r.push_back(vector<pair<long long,int>>(st.begin(), st.end()));
        }
        
        long long ans = LLONG_MIN;
        for (int i=0; i<r.size(); ++i)
            for (int j=i+1; j<r.size(); ++j)
                for (int k=j+1; k<r.size(); ++k) {
                    if (r[i][0].first+r[j][0].first+r[k][0].first<=ans) continue;

                    for (auto [v1, x1]: r[i])
                        for (auto [v2, x2]: r[j])
                            for (auto [v3, x3]: r[k]) {
                                if (x1 != x2 && x2 != x3 && x1 != x3) {
                                    ans = max(ans, v1 + v2 + v3);
                                }
                            }
                }
        return ans;
    }
};