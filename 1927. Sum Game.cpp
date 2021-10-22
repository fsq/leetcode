class Solution {
public:
    bool sumGame(string num) {
        int s1=0, s2=0, x=0, y=0;
        for (int i=0; i<num.size(); ++i)
            if (i < num.size()/2) {
                if (num[i] != '?') s1 += num[i] - '0'; else ++x;
            } else {
                if (num[i] != '?') s2 += num[i] - '0'; else ++y;
            }
        if ((x+y) & 1) return true;
        if (x > y && s1 >= s2 || x < y && s1 <= s2)
            return true;
        int t = abs(x-y), s = abs(s1-s2);
        if (t & 1) return true;
        return t/2*9 != s;
        
    }
};