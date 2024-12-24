class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        set<pair<int,int>> st;
        vector<int> mk(n);
        long long sum = 0;
        vector<long long> ans;
        for (int i=0; i<n; ++i) {
            st.insert({a[i], i});
            sum += a[i];
        }
        auto remove = [&](int id) {
            sum -= a[id];
            auto it = st.find({a[id], id});
            st.erase(it);
        };
        for (auto& q: queries) {
            int id = q[0], k = q[1];
            if (!mk[id]) {
                mk[id] = true;
                remove(id);
            }
            while (k && st.size()) {
                --k;
                auto pr = *st.begin(); 
                int id = pr.second;
                sum -= pr.first;
                st.erase(st.begin());
                mk[id] = true;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};