class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int ans = 0, i = 0;
        do {
            i += k;
            ++ans;
        } while (i<s.size() && !equal(s.begin()+i, s.end(), s.begin()));
        return ans;
    }
};