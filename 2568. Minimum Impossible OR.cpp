class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 1;
        while (st.count(ans)) ans <<= 1;
        return ans;
    }
};