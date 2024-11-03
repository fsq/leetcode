class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        unordered_set<long long> st;
        for (int i=0; i<h.size(); ++i)
            for (int j=i+1; j<h.size(); ++j)
                st.insert(abs(h[i] - h[j]));
        long long ans = -1;
        for (int i=0; i<v.size(); ++i)
            for (int j=i+1; j<v.size(); ++j) {
                long long len = abs(v[i] - v[j]);
                if (st.contains(len))
                    ans = max(ans, len * len);
            }
        return ans % 1000000007;
    }
};