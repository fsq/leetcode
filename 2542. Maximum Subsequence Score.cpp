class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return b[i] < b[j];
        });
        multiset<int> st;
        long long sum = 0, ans = 0;
        for (int i=n-1; i>=n-k+1; --i) {
            st.insert(a[p[i]]);
            sum += a[p[i]];
        }
        for (int i=n-k; i>=0; --i) {
            sum += a[p[i]];
            ans = max(ans, sum*b[p[i]]);
            if (a[p[i]] > *st.begin()) {
                st.insert(a[p[i]]);
                sum -= *st.begin();
                st.erase(st.begin());
            } else {
                sum -= a[p[i]];
            }
        }
        return ans;
    }
};