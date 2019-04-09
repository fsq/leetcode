class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string t) {
        vector<bool> ans;
        int ut = 0;
        for (auto c : t) if (isupper(c)) ++ut;
        
        for (auto& s : queries) {
            int i, j, us = 0;
            for (i=0,j=0; i<s.size(); ++i) {
                if (j<t.size() && s[i]==t[j])
                    ++j;
                if (isupper(s[i])) ++us;
            }
            ans.push_back(us==ut && j==t.size());
        }
        return ans;
    }
};