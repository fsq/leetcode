class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        vector<int> next(s.size());
        next[0] = 0;
        int i=1, j=0;
        while (i < s.size())
            if (s[i] == s[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j-1];
            } else {
                ++i;
            }

        int len = next.back();
        while (len>0 && (s.size()-len)%k != 0) {
            len = next[len-1];
        }
        if (len > 0) {
            return (s.size()-len) / k;
        } else {
            return (s.size()+k-1) / k;
        }
    }
};