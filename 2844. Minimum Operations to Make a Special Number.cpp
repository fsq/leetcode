class Solution {
public:

    int f(string& s, char a, char b) {
        int i = s.size() -1;
        while (i>=0 && s[i]!=b) --i;
        if (i<0) return INT_MAX;
        --i;
        while (i>=0 && s[i]!=a) --i;
        if (i<0) return INT_MAX;
        return s.size() - i - 2;
    }

    int minimumOperations(string num) {
        int ans = num.size() - count(num.begin(), num.end(), '0');
        ans = min(ans, f(num, '2', '5'));
        ans = min(ans, f(num, '7', '5'));
        ans = min(ans, f(num, '5', '0'));
        ans = min(ans, f(num, '0', '0'));
        return ans;
    }
};