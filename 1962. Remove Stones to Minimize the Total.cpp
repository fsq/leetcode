class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        multiset<int, greater<int>> st;
        for (auto x : a) st.insert(x);
        while (st.size() && k--) {
            auto x = *st.begin();
            if (x==1) break;
            st.erase(st.begin());
            st.insert(x - x/2);
        }
        int ans = 0;
        for (auto x : st) ans += x;
        return ans;
    }
};