class Solution {
public:
    bool ok(const string& a, const string& b, int start) {
        vector<int> c(26);
        for (int i=start; i<a.size(); i+=2) {
            ++c[a[i] - 'a'];
            --c[b[i] - 'a'];
        }
        return all_of(c.begin(), c.end(), [](int x) { return x == 0; });
    }

    bool checkStrings(string s1, string s2) {
        return ok(s1, s2, 0) && ok(s1, s2, 1);
    }
};