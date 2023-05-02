class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for (auto x : nums) {
            st.insert(x);
            int y = 0;
            while (x) {
                y = y*10 + x%10;
                x /= 10;
            }
            st.insert(y);
        }
        return st.size();
    }
};