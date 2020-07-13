class Solution {
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        multiset<pair<int,int>> st;
        for (int i=0; i<a.size(); ++i)
            st.insert({a[i], i});
        int index = 1, ans = 0, M = 100000007;
        while (index <= right) {
            auto pr = *st.begin();
            st.erase(st.begin());
            if (index >= left)
                ans = (ans + pr.first) % M;
            if (pr.second+1<a.size())
                st.insert({pr.first+a[pr.second+1], pr.second+1});
            ++index;
        }
        return ans;
    }
};