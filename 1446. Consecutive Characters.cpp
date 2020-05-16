class Solution {
public:
    int maxPower(string s) {
        int ans = 0, l = 0;
        char pre = '1';
        for (auto x : s) {
            l = x==pre ? l+1 : 1;
            pre = x;
            ans = max(ans, l);
        }
        return ans;
    }
};