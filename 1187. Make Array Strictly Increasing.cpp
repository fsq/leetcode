class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        set<int> st(a.begin(), a.end());
        for (auto x : b)
            st.insert(x);
        vector<int> s(st.begin(), st.end());
        
        int n = s.size(), mb = *min_element(b.begin(), b.end());
        unordered_set<int> sb(b.begin(), b.end());
        vector<int> f(n, INT_MAX), g(n, INT_MAX);
        
        for (int i=0; i<s.size(); ++i)
           if (s[i] >= mb && s[i] < a[0])
               g[i] = 1;
            else if (s[i] >= a[0])
                g[i] = 0;
        
        for (int i=1; i<a.size(); ++i) {
            f[0] = INT_MAX;
            for (int j=1; j<s.size(); ++j) {
                f[j] = f[j-1];
                if (g[j-1] != INT_MAX && (s[j]==a[i] || sb.count(s[j])))
                    f[j] = min(f[j], g[j-1] + (s[j]!=a[i]));
            }
            f.swap(g);
        }
        int ans = *min_element(g.begin(), g.end());
        return ans == INT_MAX ? -1 : ans;
    }
};