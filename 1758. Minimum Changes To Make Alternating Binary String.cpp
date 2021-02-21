class Solution {
public:
    int minOperations(string s) {
        int x = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] != (i&1) + '0')
                ++x;
        return min<int>(x, s.size()-x);
    }
};