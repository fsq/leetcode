class Solution {
public:
    int arithmeticTriplets(vector<int>& a, int diff) {
        unordered_set<int> st(a.begin(), a.end());
        int ans = 0;
        for (auto x : a)
            if (st.count(x-diff) && st.count(x+diff))
                ++ans;
        return ans;
    }
};