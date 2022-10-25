class Solution {
public:
    string removeDigit(string a, char digit) {
        string ans;
        for (int i=0; i<a.size(); ++i)
            if (a[i] == digit) {
                ans = max(ans, a.substr(0, i) + a.substr(i+1));
            }
        return ans;
    }
};