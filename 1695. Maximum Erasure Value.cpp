class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int ans = 0;
        unordered_set<int> st;
        for (int l=0, r=0, s=0; r<a.size(); ++r) {
            while (st.count(a[r])) {
                s -= a[l];
                st.erase(a[l++]);
            }
            st.insert(a[r]);
            s += a[r];
            ans = max(ans, s);
        }
        return ans;
    }
};