class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> st;
        int l = 0;
        for (auto x : rolls) {
            st.insert(x);
            if (st.size()==k) {
                st.clear();
                ++l;
            }
        }
        return l + 1;
    }
};