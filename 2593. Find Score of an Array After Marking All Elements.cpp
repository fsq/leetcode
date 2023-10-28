class Solution {
public:
    long long findScore(vector<int>& a) {
        set<pair<int,int>> st;
        for (int i=0; i<a.size(); ++i) st.insert({a[i], i});

        long long ans = 0;
        while (st.size()) {
            auto pr = *st.begin();
            st.erase(st.begin());
            int x = pr.first, i = pr.second;
            ans += x;
            if (i+1<a.size()) {
                auto it = st.find({a[i+1], i+1});
                if (it != st.end()) st.erase(it);
            }
            if (i-1>=0) {
                auto it = st.find({a[i-1], i-1});
                if (it != st.end()) st.erase(it);
            }
        }
        return ans;
    }
};