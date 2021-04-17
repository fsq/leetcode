class Solution {
public:
    int secondHighest(string s) {
        int lg=-1, sl=-1;
        for (auto c : s)
            if (isdigit(c)) {
                int x = c-'0';
                if (x > lg) {
                    sl = lg;
                    lg = x;
                } else if (x > sl && x != lg) {
                    sl = x;
                }
            }
        return sl;
    }
};