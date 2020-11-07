class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        multiset<int> st;
        long long sum = 0, large = 0;
        for (int i=1; i<a.size(); ++i) {
            if (a[i] <= a[i-1]) continue;
            int gap = a[i] - a[i-1];
            sum += gap;
            st.insert(gap);
            large += gap;
            if (st.size() > l) {
                large -= *st.begin();
                st.erase(st.begin());
            }
            if (sum - large > b)
                return i-1;
        }
        return a.size() - 1;
    }
};