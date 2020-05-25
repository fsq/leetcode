class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowel = {'a','e','i','o','u'};
        int ans = 0;
        for (int cur=0,r=0; r<s.size(); ++r) {
            cur += vowel.count(s[r]);
            if (r-k>=0) cur -= vowel.count(s[r-k]);
            ans = max(ans, cur);
        }
        return ans;
    }
};