class Solution {
public:
    int maxNonOverlapping(vector<int>& a, int target) {
        int n = a.size(), ans = 0;
        unordered_set<int> st = {0};
        for (int s=0, i=0; i<a.size(); ++i) {
            s += a[i];
            if (st.count(s-target)) {
                ++ans;
                st.clear();
                s = 0;
            } 
            st.insert(s);
        }
        return ans;
    }
};