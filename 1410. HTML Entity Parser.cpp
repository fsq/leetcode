class Solution {
public:
    string entityParser(string s) {
        unordered_map<string, char> m;
        m["&quot;"] = '\"';
        m["&apos;"] = '\'';
        m["&amp;"] = '&';
        m["&gt;"] = '>';
        m["&lt;"] = '<';
        m["&frasl;"] = '/';
        string ans;
        for (int i=0; i<s.size(); ) {
            bool found = false;
            if (s[i]=='&') 
                for (auto& pr : m)
                    if (i+pr.first.size()<=s.size() && equal(pr.first.begin(), pr.first.end(), s.begin()+i)) {
                        ans += pr.second;
                        i += pr.first.size();
                        found = true;
                        break;
                    }
            if (found) continue;
            ans += s[i++];
        }
        return ans;
    }
};