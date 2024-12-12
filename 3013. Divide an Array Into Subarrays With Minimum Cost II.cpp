class Solution {
public:

    long long minimumCost(vector<int>& a, int k, int dist) {
        --k;
        multiset<int> st(a.begin()+1, a.begin()+dist+2);
        auto ki = st.begin();
        long long s = *ki;
        for (int i=1; i<k; ++i) {
            ++ki;
            s += *ki;
        }
        long long ans = s;
        for (int i=2; i+dist<a.size(); ++i) {
            if (a[i+dist] > *ki) {
                st.insert(a[i+dist]);
            } else {
                st.insert(ki, a[i+dist]);
                s -= *ki;
                s += a[i+dist];
                --ki;
            }

            if (a[i-1] <= *ki) {
                s -= a[i-1];
                ++ki;
                s += *ki;
                st.erase(st.lower_bound(a[i-1]));
            } else {
                st.erase(prev(st.upper_bound(a[i-1])));
            }
            ans = min(ans, s);
        }
        return ans + a[0];
    }
};