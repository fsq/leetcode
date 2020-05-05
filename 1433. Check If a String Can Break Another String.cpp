class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> a(26), b=a;
        for (auto c : s1) ++a[c-'a'];
        for (auto c : s2) ++b[c-'a'];
        for (int i=1; i<26; ++i) {
            a[i] += a[i-1];
            b[i] += b[i-1];
        }
        auto bg = [](vector<int>& a, vector<int>& b) {
            for (int i=0; i<a.size(); ++i)
                if (a[i] > b[i])
                    return false;
            return true;
        };
        return bg(a, b) || bg(b, a);
    }
};