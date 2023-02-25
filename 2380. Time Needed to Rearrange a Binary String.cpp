class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int j = 0, p = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '1') {
                if (i != j)
                    p = j==0 ? i : max(p + 1, i - j);
                ++j;
            }
        return p;
    }
};