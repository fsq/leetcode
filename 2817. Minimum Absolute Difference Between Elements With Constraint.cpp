class Solution {
public:
    int minAbsoluteDifference(vector<int>& a, int d) {
        set<int> st;
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            if (i - d >= 0) {
                st.insert(a[i - d]);
            }
            int x = a[i];
            auto it = st.lower_bound(x);
            if (it != st.end()) {
                ans = min(ans, *it - x);
            }
            if (it != st.begin()) {
                ans = min(ans, x - *prev(it));
            }
            if (ans == 0) break;
        }
        return ans;
    }
};