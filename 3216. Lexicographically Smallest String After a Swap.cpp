class Solution {
public:
    string getSmallestString(string s) {
        auto ans = s;
        for (int i=0; i+1<s.size(); ++i) {
            int b1 = (s[i]-'0') & 1;
            int b2 = (s[i+1]-'0') & 1;
            if (!(b1 ^ b2)) {
                auto t = s;
                swap(t[i], t[i+1]);
                ans = min(ans ,t);
            }
        }
        return ans;
    }
};