class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        set<int> st(a.begin(), a.end());
        long long tot = 0;
        for (int i=0; i<a.size(); ++i) tot += abs(a[i] - b[i]);
        long long ans = tot;
        
        for (int i=0; i<a.size(); ++i) {
            long long t1, t2;
            auto it = st.upper_bound(b[i]);
            if (it != st.end()) {
                t1 = tot - abs(a[i] - b[i]) + abs(*it - b[i]);
            }
            if (it != st.begin()) {
                t2 = tot - abs(a[i] - b[i]) + abs(*prev(it) - b[i]);
            }
            ans = min(ans, min(t1, t2));
        }
        return ans % 1000000007;
    }
};