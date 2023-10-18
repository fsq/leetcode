class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        unordered_set<char> vw = {'a', 'e', 'i', 'o', 'u'};
        for (int i=left; i<=right; ++i)
            if (vw.count(words[i][0]) && vw.count(words[i].back()))
                ++ans;
        return ans;
    }
};