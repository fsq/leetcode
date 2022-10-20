class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& x : words)
            if (x.size()<=s.size() && equal(x.begin(), x.end(), s.begin()))
                ++ans;
        return ans;
    }
};