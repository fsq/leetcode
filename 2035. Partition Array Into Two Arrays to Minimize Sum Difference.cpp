class Solution {
public:
    int minimumDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> b(a.begin()+a.size()/2, a.end());
        a.resize(b.size());
        int n = a.size();
        unordered_map<int, set<int>> m;

        for (int i=0; i<(1<<n); ++i) {
            int s1=0, s2=0, cnt=0;
            for (int j=0; j<n; ++j)
                if ((i>>j) & 1) {
                    s1 += b[j];
                    ++cnt;
                } else
                    s2 += b[j];
            m[cnt].insert(s1 - s2);
        }

        int ans = abs(accumulate(a.begin(),a.end(),0) - 
                      accumulate(b.begin(),b.end(),0));
        for (int i=1; i<(1<<n)-1; ++i) {
            int s1=0, s2=0, cnt=0;
            for (int j=0; j<n; ++j)
                if ((i>>j) & 1) {
                    s1 += a[j];
                    ++cnt;
                } else
                    s2 += a[j];
            int df = s1 - s2;
            const auto& st = m[n-cnt];
            auto it = st.lower_bound(-df);
            if (it != st.end()) {
                ans = min(ans, abs(df + *it));
            }
            if (it != st.begin()) {
                ans = min(ans, abs(df + *prev(it)));
            }
        }
        return ans;
    }
};