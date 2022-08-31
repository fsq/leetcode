class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int x=1,c=0; c<k; ++x)
            if (!st.count(x)) {
                ans += x;
                ++c;
            }
        return ans;
    }
};