class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> p(26, -1);
        int ans = -1;
        for (int i=0; i<s.size(); ++i) {
            auto c = s[i];
            if (p[c-'a'] == -1)
                p[c-'a'] = i;
            else
                ans = max(ans, i - p[c-'a'] - 1);
        }
        return ans;
    }
};