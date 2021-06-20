class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intv, vector<int>& queries) {
        set<vector<int>> st;
        for (int i=0; i<queries.size(); ++i) {
            st.insert({queries[i],i});
        }
        sort(intv.begin(), intv.end(), [](vector<int>& a, vector<int>& b) {
            return a[1]-a[0] < b[1]-b[0];
        }); 
        
        vector<int> ans(queries.size(), -1);
        for (auto& it : intv) {
            if (st.empty()) break;
            int l = it[0], r = it[1];
            auto i = st.lower_bound({l, -1});
            while (i != st.end() && (*i)[0]<=r) {
                ans[(*i)[1]] = r - l + 1;
                i = st.erase(i);
            }
        }
        return ans;
    }
};