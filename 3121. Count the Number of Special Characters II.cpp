class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> lo(26,-1), up(26, -1);
        for (int i=0; i<s.size(); ++i)
            if (islower(s[i])) {
                lo[s[i]-'a'] = i;
            } else if (up[s[i]-'A']==-1) {
                up[s[i]-'A'] = i;
            }
        int ans = 0;
        for (int i=0; i<26; ++i)
            if (lo[i]==-1 && up[i]==-1)
                continue;
            else if (lo[i]!=-1 && up[i]!=-1 && lo[i]<up[i])
                ++ans;
        return ans;
    }
};