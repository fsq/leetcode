class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        multiset<int, std::greater<int>> st;
        for (auto x : nums) {
            st.insert(x);
            if (st.size() > k) {
                st.erase(prev(st.end()));
            }
        }
        vector<int> ans;
        for (auto x : nums)
            if (st.count(x)) {
                ans.push_back(x);
                st.erase(st.find(x));
            }
        return ans;
    }
};