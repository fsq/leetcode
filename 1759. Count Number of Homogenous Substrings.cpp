class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        for (int i=0,j=0; i<s.size(); i=j) {
            while (j<s.size() && s[j]==s[i]) ++j;
            long long l = j - i;
            ans = (ans + (1+l)*l/2) % 1000000007;
        }
        return ans;
    }
};