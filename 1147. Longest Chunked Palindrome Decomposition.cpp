class Solution {
public:
    int longestDecomposition(string s) {
        if (s.empty()) return 0;
        if (s.size()==1) return 1;
        for (int i=1; i<=s.size()-i; ++i)
            if (equal(s.begin(), s.begin()+i, s.begin()+s.size()-i))
                return 2 + longestDecomposition(s.substr(i, s.size()-2*i));
        return 1;
    }
};