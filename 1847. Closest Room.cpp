class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& a, vector<vector<int>>& qs) {
        for (int i=0; i<qs.size(); ++i) {
            swap(qs[i][0], qs[i][1]);
            qs[i].push_back(i);
        }
        for (auto& r : a) swap(r[0], r[1]);
        sort(qs.begin(), qs.end());
        sort(a.begin(), a.end());
        
        set<int> st;
        vector<int> ans(qs.size(), -1);
        for (int i = a.size()-1, j=qs.size()-1; j>=0; --j) {
            const auto& q = qs[j];
            while (i>=0 && a[i][0]>=q[0]) {
                st.insert(a[i][1]);
                --i;
            }
            if (st.empty()) continue;
            ans[q[2]] = INT_MAX;
            auto it = st.upper_bound(q[1]);
            if (it!=st.begin()) ans[q[2]] = *prev(it);
            if (it!=st.end() && *it-q[1]<abs(q[1]-ans[q[2]])) ans[q[2]] = *it;
        }
        return ans;
    }
};