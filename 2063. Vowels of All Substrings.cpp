class Solution {
public:
    long long countVowels(string s) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        long long ans = 0;
        for (int i=0; i<s.size(); ++i)
            if (v.count(s[i])) {
                ans += (long long)(i+1) * (s.size()-i);
            }
        return ans;
    }
};