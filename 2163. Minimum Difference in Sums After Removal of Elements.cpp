class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        vector<long long> mns(a.size());
        int n = a.size() / 3;
        multiset<int, std::greater<int>> st;
        long long sum = 0;
        for (int i=0; i<n; ++i) {
            st.insert(a[i]);
            sum += a[i];
        }
        mns[n-1] = sum;
        for (int i=n; i<2*n; ++i) {
            sum += a[i];
            st.insert(a[i]);
            sum -= *st.begin();
            st.erase(st.begin());
            mns[i] = sum;
        }

        multiset<int> sm;
        sum = 0;
        for (int i=3*n-1; i>=2*n; --i) {
            sum += a[i];
            sm.insert(a[i]);
        }
        long long ans = mns[2*n-1] - sum;
        for (int i=2*n-1; i>=n; --i) {
            sum += a[i];
            sm.insert(a[i]);
            sum -= *sm.begin();
            sm.erase(sm.begin());
            ans = min(ans, mns[i-1]-sum);
        }
        return ans;
        
    }
};