class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        unordered_map<string, string> m;
        for (auto& pr : know) m[pr[0]] = pr[1];
        string ans;
        for (int j,i=0; i<s.size(); )
            if (s[i]=='(') {
                for (j=i+1; s[j]!=')'; ++j);
                string t = s.substr(i+1, j-i-1);
                if (m.count(t))
                    ans += m[t];
                else
                    ans += "?";
                i = j + 1;
            } else {
                ans += s[i++];
            }
        return ans;
    }
};