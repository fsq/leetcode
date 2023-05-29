class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(), a.end());
        unordered_set<int> st;
        for (int i=0, j=a.size()-1; i<j; ++i, --j) st.insert(a[i]+a[j]);
        return st.size();
    }
};