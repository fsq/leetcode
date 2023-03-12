class Solution {
public:

    bool ispan(const string& s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }

    string convert(int x, int b) {
        string ans;
        while (x) {
            ans.push_back('0' + x%b);
            x /= b;
        }
        return ans;
    }

    bool isStrictlyPalindromic(int n) {
        for (int b=2; b<=n-2; ++b)
            if (!ispan(convert(n, b)))
                return false;
        return true;
    }
};