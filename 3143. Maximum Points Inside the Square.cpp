class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& ps, string s) {
        auto side = [](vector<int>& a) {
            return max(abs(a[0]), abs(a[1]));
        };
        vector<int> a(ps.size());
        iota(a.begin(), a.end(), 0);
        sort(a.begin(), a.end(), [&](int x, int y) {
            return side(ps[x]) < side(ps[y]);
        });
        int len = 0;
        unordered_set<char> st;
        for (int j,i=0; i<a.size(); i=j) {
            len = side(ps[a[i]]);
            for (j=i; j<a.size(); ++j) {
                if (side(ps[a[j]]) == len) {
                    if (st.count(s[a[j]])) {
                        return len - 1;
                    }
                    st.insert(s[a[j]]);
                } else 
                    break;
            }
        }
        return len;
    }
};