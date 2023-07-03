class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> st, vis;
        for (auto x : nums) st.insert(x);
        int ans = -1;
        for (long long x : nums)
            if (!vis.count(x)) {
                int len = 0;
                while (st.count(x)) {
                    vis.insert(x);
                    x = x*x;
                    ++len;
                }
                if (len > 1) ans = max(ans, len);
            }
        return ans;
    }
};