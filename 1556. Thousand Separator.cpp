class Solution {
public:
    string thousandSeparator(int n) {
        if (n==0) return "0";
        string ans;
        int b = 0;
        while (n) {
            ans.push_back(n%10 + '0');
            n /= 10;
            if (b==2) ans.push_back('.');
            b = (b+1) % 3;
        }
        if (ans.back() == '.') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};