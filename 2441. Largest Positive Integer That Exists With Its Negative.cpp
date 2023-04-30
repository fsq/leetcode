class Solution {
public:
    int findMaxK(vector<int>& a) {
        unordered_set<int> st(a.begin(), a.end());
        int ans = -1;
        for (auto x : a)
            if (x > 0 && st.count(-x))
                ans = max(ans, x);
        return ans;
    }
};