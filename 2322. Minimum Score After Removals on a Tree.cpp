class Solution {
public:
    int xs = 0, ans = INT_MAX;
    vector<int>* a;
    vector<int> st;

    int f(vector<vector<int>>& e, int x, int fa, bool root) {
        int sub = (*a)[x];
        for (auto y : e[x])
            if (y != fa) {
                sub ^= f(e, y, x, false);
            }
        if (!root) st.push_back(sub);
        return sub;
    }

    int minimumScore(vector<int>& oa, vector<vector<int>>& edges) {
        a = &oa;
        for (auto x : oa) xs ^= x;
        vector<vector<int>> e(oa.size());
        for (auto& p : edges) {
            e[p[0]].push_back(p[1]);
            e[p[1]].push_back(p[0]);
        }
        for (int i=0; i<oa.size(); ++i)
            for (auto y : e[i]) {
                st.clear();
                int sub = f(e, y, i, true);
                for (auto s1 : st) {
                    int s2 = sub ^ s1;
                    int s3 = xs ^ sub;
                    ans = min(ans, max(max(s1, s2), s3) - min(min(s1, s2), s3));
                }
            }
        return ans;
    }
};