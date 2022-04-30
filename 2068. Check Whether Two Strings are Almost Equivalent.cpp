class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> a(26), b(26);
        for (auto c : word1) ++a[c-'a'];
        for (auto c : word2) ++b[c-'a'];
        for (int i=0; i<26; ++i)
            if (abs(a[i]-b[i]) > 3)
                return false;
        return true;
    }
};