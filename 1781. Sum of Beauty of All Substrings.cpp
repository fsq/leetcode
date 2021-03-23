class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            multiset<int> st;
            vector<int> f(128);
            for (int j=i; j<s.size(); ++j) {
                if (f[s[j]] > 0) 
                    st.erase(st.lower_bound(f[s[j]]));
                st.insert(++f[s[j]]);
                ans += *prev(st.end()) - *st.begin();
            }
        }
        return ans;
    }
};