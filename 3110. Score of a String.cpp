class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i=0; i+1<s.size(); ++i)
            ans += abs(s[i] - s[i+1]);
        return ans;
    }
};