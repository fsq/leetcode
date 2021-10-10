class Solution {
public:
    int eliminateMaximum(vector<int>& s, vector<int>& v) {
        multiset<int, std::less<int>> st;
        for (int i=0; i<s.size(); ++i)
            st.insert((s[i]+v[i]-1)/v[i]);
        int t = 0;
        while (st.size() && *st.begin()>t) {
            st.erase(st.begin());
            ++t;
        }
        return t;
    }
};