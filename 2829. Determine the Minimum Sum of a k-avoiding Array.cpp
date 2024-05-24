class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int ans = 0, cnt = 0;
        for (int x=1; cnt<n; ++x)
            if (!st.count(x) && !st.count(k-x)) {
                st.insert(x);
                st.insert(k-x);
                ++cnt;
                ans += x;
            }
        return ans;
    }
};