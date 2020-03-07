class Solution {
public:
    string toHex(int x) {
        if (!x) return "0";
        int mask = 0xf;
        string ans;
        string s = "0123456789abcdef";
        for (int i=0; i<8; ++i) {
            int y = x & mask;
            x >>= 4;
            ans += s[y];
        }
        while (ans.size() && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};