class Solution {
public:
    int countVowelSubstrings(string s) {
        int ans = 0;
        set<char> tar = {'a', 'e', 'i', 'o', 'u'};
        for (int l=0; l<s.size(); ++l) 
            for (int r=l; r<s.size(); ++r) {
                auto t = s.substr(l, r-l+1);
                ans += set<char>(t.begin(), t.end()) == tar;
            }
        return ans;
    }
};