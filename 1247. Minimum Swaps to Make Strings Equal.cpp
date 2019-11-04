class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int m=0, n=0;
        for (int i=0; i<s1.size(); ++i)
            if (s1[i]=='x' && s2[i]=='y')
                ++m;
            else if (s1[i]=='y' && s2[i]=='x')
                ++n;
        if ((m&1) ^ (n&1)) return -1;
        int ans = m/2 + n/2;
        if (m & 1) ans += 2;
        return ans;
    }
};