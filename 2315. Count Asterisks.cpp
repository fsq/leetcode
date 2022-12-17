class Solution {
public:
    int countAsterisks(string s) {
        int ans = count(s.begin(), s.end(), '*');
        for (int j=0, i=0; i<s.size(); ) 
            if (s[i] != '|')
                ++i;
            else {
                for (j=i+1; j<s.size() && s[j]!='|'; ++j) {
                    if (s[j]=='*') --ans;
                }
                i = j + 1;
            }
        return ans;
    }
};