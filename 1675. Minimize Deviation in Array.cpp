class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        multiset<pair<int,int>> st;
        for (auto x : a) {
            if (x & 1) 
                st.insert({x, x*2});
            else {
                int y;
                for (y=x; !(y&1); y>>=1);
                st.insert({y, x});
            }
        }
        int ans = INT_MAX;
        while (true) {
            int x = st.begin()->first, y = st.begin()->second;
            int lst = prev(st.end())->first;
            ans = min(ans, lst-x);
            if (x*2 <= y) {
                st.erase(st.begin());
                st.insert({x*2, y});
            } else
                break;
        }
        return ans;
    }
};