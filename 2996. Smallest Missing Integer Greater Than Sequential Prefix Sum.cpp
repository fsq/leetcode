class Solution {
public:
    int missingInteger(vector<int>& a) {
        unordered_set<int> st(a.begin(), a.end());
        int len=1, mx=a[0];
        for (int i=1; i<a.size(); ++i) {
            if (a[i] == a[i-1] + 1) {
                ++len;
                mx += a[i];
            } else {
                break;
            }
        }
        int ans = mx;
        while (st.count(ans)) ++ans;
        return ans;
    }
};