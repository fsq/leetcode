class Solution {
public:
    int minimumDeletions(string s) {
        int ta = count(s.begin(), s.end(), 'a');
        int ans = min<int>(ta, s.size()-ta);
        for (int a=0, b=0, i=0; i<s.size(); ++i) {
            if (s[i]=='a') ++a; else ++b;
            ans = min(ans, b + ta-a);
        }
        return ans;
    }
};