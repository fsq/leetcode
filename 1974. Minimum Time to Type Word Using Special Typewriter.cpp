class Solution {
public:
    int minTimeToType(string s) {
        int ans = s.size();
        char cur = 'a';
        for (int i=0; i<s.size(); ++i) {
            char x = s[i];
            ans += min(abs(x-cur), 26-abs(x-cur));
            cur = x;
        }
        return ans;
    }
};