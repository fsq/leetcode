class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        int i = 0;
        while (n) {
            if (n & 1) ++ans[i];
            n >>= 1;
            i ^= 1;
        }
        return ans;
    }
};