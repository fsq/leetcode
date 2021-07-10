class Solution {
public:
    bool checkZeroOnes(string s) {
        int l0=0, l1=0;
        int c0=0, c1=0;
        for (auto c : s)
            if (c=='0') {
                ++c0;
                c1 = 0;
                l0 = max(l0, c0);
            } else {
                ++c1;
                c0 = 0;
                l1 = max(l1, c1);
            }
        return l1 > l0;
    }
};