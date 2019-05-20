class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        multiset<int, std::greater<int>> st(a.begin(), a.end());
        while (st.size() > 1) {
            auto x = *st.begin();
            st.erase(st.begin());
            auto y = *st.begin();
            st.erase(st.begin());
            if (x != y)
                st.insert(x - y);
        }
        return *st.begin();
    }
};