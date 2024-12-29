class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& a, int w) {
        set<int> st;
        for (auto& p: a) st.insert(p[0]);
        int ans = 0;
        for (auto it=st.begin(), p=it; it!=st.end(); it=p) {
            for (p=it; p!=st.end() && *p-*it<=w; ++p);
            ++ans;
        }
        return ans;
    }
};