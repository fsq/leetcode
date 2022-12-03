class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (auto i=st.begin(); i!=st.end(); ) {
            auto j = i;
            while (j!=st.end() && *j-*i<=k) ++j;
            ++ans;
            i = j;
        }
        return ans;
    }
};