class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> f(32,-2);
        f[0] = -1;
        string vowel = "aeiou";
        int ans = 0, now = 0;
        for (int i=0; i<s.size(); ++i) {
            auto it = vowel.find(s[i]);
            if (it!=string::npos) 
                now ^= 1 << it;
            
            if (f[now] != -2) 
                ans = max(ans, i-f[now]);
            else
                f[now] = i;
        }
        return ans;
    }
};