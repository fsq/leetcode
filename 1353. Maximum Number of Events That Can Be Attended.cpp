class Solution {
public:
    int maxEvents(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        multiset<int> st;
        int ans = 0;
        for (int i=0, d=0; i<a.size() || st.size(); ) {
            if (st.empty()) d = a[i][0];
            while (i<a.size() && a[i][0]==d) 
                st.insert(a[i++][1]);
            ++ans, ++d;
            st.erase(st.begin());
            while (st.size() && *st.begin()<d) st.erase(st.begin());
        }
        return ans;
    }
};