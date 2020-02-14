class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (auto x : arr) {
            if (st.count(x*2) || !(x&1) && st.count(x>>1))
                return true;
            st.insert(x);
        }
        return false;
    }
};