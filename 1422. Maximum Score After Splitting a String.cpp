class Solution {
public:
    int maxScore(string s) {
        int a1 = count(s.begin(), s.end(), '1');
        int ans = 0, c1=0, c2=0;
        for (int i=0; i+1<s.size(); ++i) {
            auto x = s[i];
            if (x=='1') ++c1; else ++c2;
            ans = max(ans, c2 + a1 - c1);
        }
        return ans;
    }
};